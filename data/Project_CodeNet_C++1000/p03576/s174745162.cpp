#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

#define ld long double
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pi pair<int,int>

#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;

#define INF LONG_LONG_MAX

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k; cin>>n>>k;
    vll x(n),y(n);
    rep(i,n) cin>>x[i]>>y[i];
    vll sx, sy;
    sx = x, sy = y;
    sort(all(sx));
    sort(all(sy));
    ll ans=INF;
    rep(a,n)rep(b,n)rep(c,n)rep(d,n){
        if (a>b || c>d) continue;
        int cnt=0;
        rep(i,n)if(sx[a]<=x[i]&&x[i]<=sx[b]&&sy[c]<=y[i]&&y[i]<=sy[d]){
            cnt++;
        }
        if (cnt>=k) chmin(ans,(sx[b]-sx[a])*(sy[d]-sy[c]));
    }
    cout<<ans<<endl;
    return 0;
}
