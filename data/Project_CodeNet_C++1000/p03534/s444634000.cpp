#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define maxn 100005
char s[maxn];
int a[3];
int main()
{
    scanf("%s", s);
    for(int i = 0; i < strlen(s); i++) {
        if(s[i] == 'a') a[0]++;
        else if(s[i] == 'b') a[1]++;
        else a[2]++;
    }
    sort(a, a+3);
    int ok=0;
    if(a[2]-a[0] == 1 || a[2]-a[0] == 0) ok = 1;
    if(ok) printf("YES\n");
    else printf("NO\n");
    return 0;
}
