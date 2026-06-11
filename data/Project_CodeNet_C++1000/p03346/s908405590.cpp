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
#define ma 200005

ll a[ma],b[ma];

int main()
{
    ll n,i,j;
    while(cin>>n)
    {
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
            b[a[i]]=i;
        }
        ll cn=0;
        ll pre=0;
        ll max1=0;
        for(i=1;i<=n;i++)
        {
            if(b[i]>pre)
            {
                pre=b[i];
                cn++;
            }
            else
            {
                pre=b[i];
                cn=1;
            }
            max1=max(max1,cn);
        }
        cout<<n-max1<<endl;
    }
    return 0;
}
