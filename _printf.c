#include "main.h"

/**
 * _printf - Custom implementation of printf
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;
    char *str;

    if (!format)
        return (-1);

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'c')
                count += _putchar(va_arg(args, int));
            else if (format[i] == 's')
            {
                str = va_arg(args, char *);
                if (!str)
                    str = "(null)";
                while (*str)
                    count += _putchar(*str++);
            }
            else if (format[i] == '%')
                count += _putchar('%');
            else
            {
                count += _putchar('%');
                count += _putchar(format[i]);
            }
        }
        else
            count += _putchar(format[i]);
        i++;
    }

    va_end(args);
    return (count);
}
