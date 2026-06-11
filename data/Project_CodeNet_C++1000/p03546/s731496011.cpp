#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define FORR(i,m,n) for(int i = m - 1; i >= n; i--)
#define ALL(v) v.begin(), v.end()
#define itn int
#define Yes() cout << "Yes" << endl
#define No() cout << "No" << endl
#define YES() cout << "YES" << endl
#define NO() cout << "NO" << endl
#define println(x) cout << x << endl
#define print(x) cout << x << " "
template<typename T, typename U>
inline bool CMAX(T &m, U x) { if (m < x) { m = x; return true; } return false; }
template<typename T, typename U>
inline bool CMIN(T &m, U x) { if (m > x) { m = x; return true; } return false; }

typedef long long lint;
typedef long double ldouble;
const int INF = 1e9;
const lint LINF = 1e18;
const int MOD = 1e9+7;
int main(){
    int h,w;
    cin >>h >> w;
    lint ans = 0;
    vector<vector<int>> cost(10,vector<int>(10,INF));
    REP(i,10){
        REP(j,10){
            cin >> cost[i][j];
        }
    }
    REP(i,10){
        REP(j,10){
            REP(k,10){
                cost[j][k] = min(cost[j][k] , cost[j][i] + cost[i][k]);
            }
        }
    }

    REP(i,h){
        REP(j,w){
            int a;
            cin >> a;
            if(a != -1){
                ans += cost[a][1];
            }
        }
    }
    println(ans);
    return 0;
}