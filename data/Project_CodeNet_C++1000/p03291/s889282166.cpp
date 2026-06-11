#include<cstdio>
#include<cstring>

const int S_MAX = 1e5, A = 1e9 + 7;
char s[S_MAX + 1];
int a[S_MAX], b[S_MAX], c[S_MAX];

int main() {
    scanf("%s", s);
    int l = strlen(s);
    
    int q = 1;
    if (s[0] == 'A' || s[0] == '?') a[0] = 1;
    if (s[0] == '?') q = 3;
    for (int i = 1; i < l; i++) {
        switch (s[i]) {
            case 'A':
                a[i] = (a[i - 1] + q) % A;
                b[i] = b[i - 1];
                c[i] = c[i - 1];
                break;
            case 'B':
                a[i] = a[i - 1];
                b[i] = (b[i - 1] + a[i - 1]) % A;
                c[i] = c[i - 1];
                break;
            case 'C':
                a[i] = a[i - 1];
                b[i] = b[i - 1];
                c[i] = (c[i - 1] + b[i - 1]) % A;
                break;
            case '?':
                a[i] = (static_cast<long>(3) * a[i - 1] + q) % A;
                b[i] = (static_cast<long>(3) * b[i - 1] + a[i - 1]) % A;
                c[i] = (static_cast<long>(3) * c[i - 1] + b[i - 1]) % A;
                q = static_cast<long>(q) * 3 % A;
                break;
        }
    }

    printf("%d\n", c[l - 1]);
    return 0;
}
