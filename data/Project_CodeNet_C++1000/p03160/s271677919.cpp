#include <bits/stdc++.h>
 
using namespace std;

#define INF 1e9
#define LINF 1e18
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define VPII vector<PII>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
 
template<class C> void mini(C& _a4, C _b4) { _a4 = min(_a4, _b4); }
template<class C> void maxi(C& _a4, C _b4) { _a4 = max(_a4, _b4); }
 
template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}
 
template<class T> ostream& operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto& vv : V) os << vv << ","; os << "]";
  return os;
}
 
#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif
 
#define MAX 501

int N;
VI H;
int min_cost = LINF;
VI cost;

void dp(int n,int sum_cost){
    if(n == N-1){
        if(min_cost > sum_cost){
            min_cost = sum_cost;
        }
    }
    if(n >= N){
        return;
    }
    dp(n+1,sum_cost + abs(H[n]-H[n+1]));
    dp(n+2,sum_cost + abs(H[n]-H[n+2]));
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(11);
    cerr << fixed << setprecision(6);

    cin >> N;
    H.assign(N,-1);
    cost.assign(N,LINF);
    R(i,N) cin >> H[i];
    //dp(0,0);
    //
    cost[0] = 0;
    cost[1] = abs(H[0]-H[1]); 
    FOR(i,2,N){
        cost[i] = min(cost[i-1]+abs(H[i]-H[i-1]),cost[i-2]+abs(H[i]-H[i-2]));
    }
    min_cost = cost[N-1];
    //cout << to_string(N) << endl;
    //R(i,N) cout << to_string(H[i]) << endl;
    cout << to_string(min_cost) << endl;
}
