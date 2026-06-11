#include <stdio.h>
#include <string.h>
using namespace std;
char a[100];
int main()
{
    scanf("%s", a);
    int len = strlen(a);
    for (int i = 0; i < len - 8; i++) putchar(a[i]);
    puts("");
    return 0;
}