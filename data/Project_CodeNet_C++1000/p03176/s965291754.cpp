#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define rev(r) reverse(r.begin(),r.end())
#define SORT(ar) sort(ar.begin(), ar.end())
#define sz(x) (int)(x).size()
#define len(x) (int)x.length()
#define in(a) scanf("%lld",&a)
#define pr(x) printf("%d ",x)
#define endl '\n'
#define read(v,n) for(int h=0;h<n;h++) cin>>v[h];
#define fo(i,a,b) for(i=a;i<b;i++)
#define fi(i,a,b) for(i=a;i>=b;i--)
#define mo 1000000007
#define N 200007
ll bit[N];

void update(ll j,ll x)
{
    for(;j<N;j+=j&(-j))
        bit[j]=max(bit[j],x);
}
ll query(ll j)
{
    ll x=INT_MIN;
    for(;j>0;j-=(j)&(-j))
        x=max(bit[j],x);
    return x;
}

int main()
{
    ll n,x,i,q,y;
    in(n);
    ll h[n+1],a[n+1];
    fo(i,1,n+1) in(h[i]);
    fo(i,1,n+1) in(a[i]);
    fo(i,1,n+1)
    {

        update(h[i],query(h[i])+a[i]);
    }
    cout<<query(n)<<endl;
}
