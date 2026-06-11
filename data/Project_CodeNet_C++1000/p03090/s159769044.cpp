/*
Nahid Hossain
Jahangirnagar University
Roll:54
*/
#include<bits/stdc++.h>
#include<string.h>
#define ll long long
#define pf printf
#define sf scanf
#define ff first
#define ss second
#define clr clear()
#define sz size()
#define pb push_back
#define mk make_pair
#define pi acos(-1)
#define inf 2000000000000000000
#define mod 1000000007
#define ull unsigned long long int
#define f(i,k,n) for(i=k;i<n;i++)
#define fr(i,n,k) for(i=n;i>=k;i--)
#define ent(a) scanf("%lld",&a)
#define ent2(a,b) scanf("%lld%lld",&a,&b)
#define ent3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define mem(a) memset(a,0,sizeof(a))
#define vec(v,s) vector<ll>v[s]
#define arr(a,s) ll a[s];
//knight and king//
int dr[]= {2,2,-2,-2,1,-1,1,-1};
int dc[]= {1,-1,1,-1,2,2,-2,-2};
int dr1[]= {0,0,1,1,1,-1,-1,-1};
int dc1[]= {1,-1,1,0,-1,0,1,-1};
int dr2[]= {0,0,1,-1};
int dc2[]= {1,-1,0,0};
////////////////////////////
using namespace std;
#define ma 105



ll sum(ll x)
{
    return (x*(x+1))/2;
}

ll a[ma],n;

ll check(ll x)
{
    ll i,j;
    for(i=1;i<=n;i++)
    {
        ll p=a[i]-x;
        if(p==i)return 0;
    }
    return 1;
}
ll e[ma][ma];
int main()
{
    ll i,j;
    while(cin>>n)
    {
        for(i=1;i<=n;i++)a[i]=sum(n)-i;

        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)e[i][j]=1;
        }
        ll sum=0;
        for(i=a[n];i>=1;i--)
        {
            if(check(i))
            {
                sum=i;
                break;
            }
        }

        for(i=1;i<=n;i++)
        {
            ll p=a[i]-sum;
            e[i][p]=e[p][i]=0;
        }

        vector<pair<ll,ll> > v;
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)if(e[i][j])v.pb(mk(i,j));
        }

        cout<<v.sz<<endl;

        for(i=0;i<v.sz;i++)cout<<v[i].ff<<" "<<v[i].ss<<endl;


    }
    return 0;
}
