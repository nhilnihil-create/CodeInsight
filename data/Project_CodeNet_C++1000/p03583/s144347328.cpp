#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,a,b) for(int i=a;i<b;i++)
#define each(it,v) for(auto it : v)
#define mod 1000000007
#define all(v) (v).begin(),(v).end()
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pair<int,int>>
#define vv vector<vector<int>>
using namespace std;

main()
{
    ll n; cin>>n;

    for(ll a=1;a<=3500;a++)for(ll b=1;b<=3500;b++)
    {
        ll t=n*a*b,s=4*a*b-n*(a+b);
        if(s!=0)if(t%s==0)if(t/s>0)
        {
            printf("%lld %lld %lld\n",a,b,t/s);
            return 0;
        }
    }
}