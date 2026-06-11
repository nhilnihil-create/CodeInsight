#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int main()
{
    int n,q;
    scanf("%d",&n);
    scanf("%s",s+1);
    scanf("%d",&q);
    while(q--)
    {
        int k;
        scanf("%d",&k);
        long long ans=0,res=0,d=0,m=0;
        for(int i=1;i<=n;i++)
        {
            if(i>k)
            {
                if(s[i-k]=='D') d--,res-=m;
                if(s[i-k]=='M') m--;
            }
            if(s[i]=='D') d++;
            if(s[i]=='M') m++,res+=d;
            if(s[i]=='C') ans+=res;
        }
        printf("%lld\n",ans);
    }
}
