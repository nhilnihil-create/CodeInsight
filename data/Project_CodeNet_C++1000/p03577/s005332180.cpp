#include <bits/stdc++.h>
#define mod 1000000009
using namespace std;

typedef long long ll;

char s[1000005];
int main()
{
    scanf("%s",s);
    int len=strlen(s);
    for(int i=0;i<len-8;i++)
        printf("%c",s[i]);
    return 0;
}