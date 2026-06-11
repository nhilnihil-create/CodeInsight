#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n;
int main()
{
    scanf("%d",&n);
    int ans=0,l=0,r=0,flag=false;
    for(int i=1;i<=n;i++)
    {
        char s[15];
        scanf("%s",s+1);
        int m=strlen(s+1);
        if(s[1]=='B') l++;
        if(s[m]=='A') r++;
        if(!(s[1]=='B'&&s[m]=='A')&&(s[1]=='B'||s[m]=='A')) flag=true;
        for(int i=1;i<m;i++)
            if(s[i]=='A'&&s[i+1]=='B') ans++;
    }
    ans+=min(l,r);
    if(!flag&&min(l,r)>0) ans--;
    printf("%d\n",ans);
}
