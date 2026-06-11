#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<(n);++i)
#define rep2(i,a,b) for (ll i=(a);i<(b);++i)
#define debug(x) cout << #x << '=' << x << endl
#define all(v) (v).begin(),(v).end()
const ll MOD=1e9+7;
//const ll MOD=998244353;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){a=b; return true;}
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){a=b; return true;}
    return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H,W,N; cin >> H >> W >> N;
    set<Pii> s;
    vector<vector<int>> block(W);
    vector<Pii> P(N);
    rep(i,N){
        int x,y; cin >> x >> y;
        P[i]={--x,--y};
        s.insert({x,y});
    }
    sort(P.begin(),P.end());
    rep(i,N) block[P[i].second].push_back(P[i].first);
    rep(i,W) block[i].push_back(H);
    int now=0,ans=H;
    rep(i,H){
        chmin(ans,*upper_bound(block[now].begin(),block[now].end(),i));
        if (s.count({i+1,now})) break;
        if (!s.count({i+1,now+1})&&now<W-1) ++now;
    }
    cout << ans << endl;
}