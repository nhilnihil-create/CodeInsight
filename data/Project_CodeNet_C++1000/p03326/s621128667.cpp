#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(long long i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true; }return false; }
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true; }return false; }
const int INF = 1e18;
int d[2] = {1,-1};

signed main(){
    int n, m; cin >> n >> m;
    vector<priority_queue<int>> sum(8);
    REP(i,n){
        int a, b, c; cin >> a >> b >> c;
        REP(s,2)REP(t,2)REP(u,2){
            sum[4*s+t*2+u].push(a*d[s]+b*d[t]+c*d[u]);
        }
    }
    int ans = 0;
	REP(i,8){
        int pre = 0;
        REP(_,m){
            pre += sum[i].top();
            sum[i].pop();
        }
        chmax(ans,pre);
    }
    cout << ans << endl;
}