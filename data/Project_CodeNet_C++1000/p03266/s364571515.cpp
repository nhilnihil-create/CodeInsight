#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define pf push_front
#define F first
#define re return
#define S second
#define ll long long
#define f(i) return cout<<i<<"\n",0;
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define lp(i,a,b) for (int i=(a);i<=(int)(b);++i)
#define lp2(i,a,b) for (int i=(a);i>=(b);--i)
#define clr(c,x) memset(c,x,sizeof(c))
#define allr(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
const int N=2e5+5,mod=(int)1e9+7;
int cnt[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,k,ans=0;
    cin>>n>>k;
    lp(i,1,n)
    cnt[i%k]++;
    lp(i,1,n)
    {
        int y=(k-(i%k))%k;
        if ((y+y)%k!=0) continue;
        ll z=cnt[y];
        z*=z;
        ans+=z;
    }
    cout<<ans<<"\n";
    return 0;
}