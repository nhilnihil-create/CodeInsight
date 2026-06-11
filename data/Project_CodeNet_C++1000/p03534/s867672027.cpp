#include<cstdio>
#include<cstring>
#include<cstdlib>

char s[100005];

int main()
{
    scanf("%s", s);
    int lng = strlen(s);

    int a = 0, b = 0, c = 0;
    for (int i = 0; i < lng; i++) {
        if (s[i] == 'a') a++;
        if (s[i] == 'b') b++;
        if (s[i] == 'c') c++;
    }

    bool jdg = true;
    if (abs(a - b) >= 2) jdg = false;
    if (abs(b - c) >= 2) jdg = false;
    if (abs(c - a) >= 2) jdg = false;

    if (jdg) printf("YES\n");
    else printf("NO\n");
}