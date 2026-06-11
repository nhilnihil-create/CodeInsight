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
    vll sx,sy;
    sx=x, sy=y;
    sort(all(sx));
    sort(all(sy));
    sx.erase(unique(all(sx)), sx.end());
    int w = sx.size();
    sy.erase(unique(all(sy)), sy.end());
    int h = sy.size();
    unordered_map<ll,int> zipx,zipy;
    rep(i,w) zipx[sx[i]] = i;
    rep(i,h) zipy[sy[i]] = i;
    vector<vi> sum(h+1,vi(w+1));
    rep(i,n){
        int tx = zipx[x[i]];
        int ty = zipy[y[i]];
        sum[ty+1][tx+1]++;
    }
    rep(i,h+1)rep(j,w) sum[i][j+1]+=sum[i][j];
    rep(j,w+1)rep(i,h) sum[i+1][j]+=sum[i][j];
    ll ans=INF;
    rep(a,w)rep(b,w)rep(c,h)rep(d,h){
        if (a<b || c<d) continue;
        ll dx = sx[a]-sx[b];
        ll dy = sy[c]-sy[d];
        int cnt = sum[c+1][a+1]-sum[c+1][b]-sum[d][a+1]+sum[d][b];
        if (cnt>=k) chmin(ans,dx*dy);
    }
    cout<<ans<<endl;
    return 0;
}
