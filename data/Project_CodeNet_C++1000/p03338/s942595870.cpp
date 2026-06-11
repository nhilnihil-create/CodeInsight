#include <stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

int main(void)
{
    int ans = 0;
    int a[26], b[26];
    int n;
    char s[101];

    scanf("%d", &n);
    scanf("%s", s);

    for (int i = 0; i < n - 1; i++)
    {
        int tmp = 0;
        for (int j = 0; j < 26; j++)
        {
            a[j] = 0;
            b[j] = 0;
        }

        for (int j = 0; j < i + 1; j++)
            a[s[j] - 'a']++;
        for (int j = i + 1; j < n; j++)
            b[s[j] - 'a']++;

        for (int j = 0; j < 26; j++)
            if ((a[j] != 0) && (b[j] != 0))
                tmp++;
        ans = max(ans, tmp);
    }

    printf("%d\n", ans);

    return 0;
}