#include <stdio.h>
#include <stdlib.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
typedef long long ll;

int main(void)
{
    int ans = 0;
    int num;

    char s[5];
    scanf("%s", s);

    num = atoi(s);

    if (1 <= num % 100 && num % 100 <= 12)
        ans = 1;
    if (1 <= num / 100 && num / 100 <= 12 && ans == 0)
        puts("MMYY");
    else if (1 <= num / 100 && num / 100 <= 12 && ans == 1)
        puts("AMBIGUOUS");
    else if (ans == 0)
        puts("NA");
    else
        puts("YYMM");

    return 0;
}