#include <cstdio>

char x, y;

int main()
{
    scanf("%c %c", &x, &y);
    if (x < y) printf("<\n");
    else if (x == y) printf("=\n");
    else printf(">\n");

    return 0;
}