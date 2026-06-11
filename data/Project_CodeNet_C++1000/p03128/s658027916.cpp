#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll f[20001][20];
int main()
{
    ll n,m;
    cin>>n>>m;
    ll c[10];
    c[1]=2;
    c[2]=5;
    c[3]=5;
    c[4]=4;
    c[5]=5;
    c[6]=6;
    c[7]=3;
    c[8]=7;
    c[9]=6;
    ll a[m+1];
    for(ll i=1;i<=m;i++)
    {
        cin>>a[i];
        f[c[a[i]]][a[i]]=1;
    }
    sort(a+1,a+m+1);
    a[0]=0;
    for(ll i=2;i<n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            if(f[i][a[j]])
            {
                for(ll k=1;k<=m;k++)
                {
                    f[i+c[a[k]]][a[k]]=max(f[i+c[a[k]]][a[k]],f[i][a[j]]+1);
                }
            }
        }
    }
    ll k;
    for(ll i=n;i>0;i-=c[a[k]])
    {
        k=0;
        for(ll j=1;j<=m;j++)
        {
            if(f[i][a[j]] && f[i][a[j]]>=f[i][a[k]])
            {
                k=j;
            }
        }
        cout<<(char)('0'+a[k]);
    }
}