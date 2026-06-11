#include<bits/stdc++.h>
#define fail {puts("-1");return 0;}
using namespace std;
char s[100005];
int main()
{
    int n;
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n/2;i++)if(s[i]!=s[n-i])fail
    if(s[1]=='0'||s[n]=='1')fail
    int now=2;
    printf("1 2\n");
    for(int i=2;i<n;i++)
    {
        printf("%d %d\n",now,i+1);
        if(s[i]=='1')now=i+1;
    }
    return 0;
}