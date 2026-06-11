#include<bits/stdc++.h>
using namespace std;
char s[15];
int query(int x)
{
    printf("%d\n",x);
    fflush(stdout);
    scanf("%s",s);
    if(s[0]=='V') return 0;
    if(s[0]=='M') return 1;
    return 2;
}
int main()
{
    int n;scanf("%d",&n);
    int l=0,r=n-2;
    int k=query(0);
    if(k==0){return 0;}
    while(l<r)
    {
        int m=l+r>>1;
        int t;
        if(m&1) t=k==1?2:1;
        else t=k;
        int res=query(m);
        if(res==0){return 0;}
        if(res==t) l=m+1;
        else r=m-1;
    }
    for(int i=l;i<=l+1;i++)
        if(query(i)==0) break;
}
