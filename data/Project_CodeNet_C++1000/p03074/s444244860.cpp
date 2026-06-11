#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef struct n
{
    ll x,y;
}m;
m q[1000005];
char p[1000005];
int main()
{
    ll a,b,c,d,e;
    cin>>a>>b;
    cin>>p;
    char u =p[0];
    ll ans=0,n=1;
    if(p[a-1]=='1')
        p[a]='0';
    else
        p[a]='1';
    for(ll i=0;i<=a;i++)
    {
        if(u==p[i])
        {
            ans++;
        }
        else
        {
            q[n].x=ans;
            q[n].y=u-'0';
            n++;
            ans=1;
            u=p[i];
        }
    }
    ll k=0;
    ans=0;
    ll flag=0;


    for(ll i=1;i<n;i++)
    {
        if(q[i].y==0)
        {

            if(k>=b)
            {
               ans =ans+q[i].x-q[i-2*k].x -q[i-2*k-1].x;
               flag=max(flag,ans);
            }
            else
            {
                k++;
            ans+=q[i].x;
            flag=max(flag,ans);
            }


        }
        else

        {
            ans+=q[i].x;
            flag=max(flag,ans);
        }
    }
    cout<<flag;

}
