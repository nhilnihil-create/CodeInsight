#include <bits/stdc++.h>
#define ll long long
#define rw freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
#define pb push_back
#define F first
#define S second
#define pf push_front
#define lp(i,a,b) for (int i=a;i<=(int)b;++i)
#define lp2(i,a,b) for (int i=a;i>=b;--i)
#define f(x) return cout<<x<<"\n",0
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(c) c.begin(),c.end()
#define allr(c) c.rbegin(),c.rend()
#define p(x) cout<<#x<<" = { "<<x<<" } \n"
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define EPS 1e-6
#define FAST ios::sync_with_stdio(0),ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define clr(c,x) memset(c,x,sizeof(c));
using namespace std;
const int N=2e5+5;
int a[N],b[N],n;
vi bb;
int main()
{
#ifdef ONLINE_JUDGE
    FAST;
#endif
    while(cin>>n)
    {
        lp(i,1,n) cin>>a[i];
        lp(i,1,n) cin>>b[i];
        ll ans=0;
        lp(k,0,29)
        {
            ll T=(1LL<<k);
            bb.clear();
            lp(i,1,n) bb.pb(b[i]%(2*T));
            sort(all(bb));
            int cnt=0;
            lp(i,1,n)
            {
                int aa=a[i]%(2*T);
                cnt+=lower_bound(all(bb),(2*T)-aa)-lower_bound(all(bb),T-aa);
                cnt+=lower_bound(all(bb),(4*T)-aa)-lower_bound(all(bb),(3*T)-aa);
            }
            if (cnt&1)
                ans+=T;
        }
        cout<<ans<<"\n";
    }
    return 0;
}