#include<bits/stdc++.h>
using namespace std;
int n,q;
char a[200005],b[200005];
string s;
int sol(int x,int u)
{
    x--;
    for(int i=1;i<=q;i++)
        if(a[i]==s[x])
    {
        if(b[i]=='L')
        {
            x--;
            if(x<0&&!u) return 1;
        }
        else
        {
            x++;
            if(x==n&&u) return 1;
        }
    }
    return 0;
}
int main()
{
    cin>>n>>q;
    cin>>s;
    for(int j=1;j<=q;j++)
        cin>>a[j]>>b[j];
    int rez=n+1,rez1=0;
    for(int step=1<<17;step;step>>=1)
        if(rez-step>=0&&sol(rez-step,1)) rez-=step;
    for(int step=1<<17;step;step>>=1)
        if(rez1+step<=n&&sol(rez1+step,0)) rez1+=step;
    if(rez>rez1)
    cout<<rez-rez1-1;
    else cout<<0;
}
