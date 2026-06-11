#include <bits/stdc++.h>
using namespace std;

typedef int_fast32_t int32;
typedef int_fast64_t int64;

const int32 inf = 1e9+7;
const int32 MOD = 1000000007;
const int64 llinf = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define POSSIBLE(n) cout << ((n) ? "POSSIBLE\n" : "IMPOSSIBLE\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define all(obj) (obj).begin(),(obj).end()
#define rall(obj) (obj).rbegin(),(obj).rend()
#define fi first
#define se second
#define pb(a) push_back(a)
typedef pair<int32,int32> pii;
typedef pair<int64,int64> pll;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true; } return false;
}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true; } return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int32 n;
    cin >> n;
    vector<int32> t(n),v(n);
    REP(i,n)cin >> t[i];
    REP(i,n)cin >> v[i];
    vector<int32> w(n+1,inf);
    priority_queue<pii,vector<pii>,greater<pii>> que;
    REP(i,n){
        chmin(w[i], v[i]);
        chmin(w[i+1],v[i]);
    }
    REP(i,n+1){
        que.emplace(w[i],i);
    }
    w[0] = w[n] = 0;
    que.emplace(0,0);
    que.emplace(0,n);
    while(!que.empty()){
        int32 d,cur;
        tie(d,cur) = que.top();
        que.pop();
        if(w[cur] < d)continue;
        if(cur-1 >= 0 && chmin(w[cur-1], w[cur] + t[cur-1])){
            que.emplace(w[cur-1],cur-1);
        }
        if(cur+1 <= n && chmin(w[cur+1], w[cur] + t[cur])){
            que.emplace(w[cur+1],cur+1);
        }
    }
    // REP(i,n+1)cout << w[i] << " ";
    // cout << endl;

    double ans = 0;
    // 2 * x = 2 * v0 * t + a * t * t;
    REP(i,n){
        if(abs(w[i] - w[i+1]) > t[i]){
            ans += min<double>(w[i], w[i+1]) * t[i] + (double)t[i] * t[i] / 2;
        }else{
            double t0 = v[i] - w[i];
            double t1 = v[i] - w[i+1];
            if(t[i] - t0 - t1 < 0){
                double dt = -(t[i] - t0 - t1);
                t0 -= dt / 2;
                t1 -= dt / 2;
            }
            // cout << t0 << " " << t1 << endl;
            ans += w[i] * t0 + t0 * t0 / 2;
            ans += w[i+1] * t1 + t1 * t1 / 2;
            ans += v[i] * (t[i] - t0 - t1);
        }
    }
    cout << fixed << setprecision(15);
    ANS(ans);
    return 0;
}