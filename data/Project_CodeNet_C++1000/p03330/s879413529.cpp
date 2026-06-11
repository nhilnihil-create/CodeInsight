#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
#include <iomanip>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<long double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }
#define INF 1LL<<60

int N, C;

int dfs(int from, int mod, vector<bool> color_used, vector<bool> mod_used,
        vector< vector<int> >& D, vector< vector<int> >& c, vector< vector<int> >& mod_color_score) {
    // cerr << "color: " << from << " mod: " << mod << endl;
    color_used[from] = true;
    mod_used[mod] = true;

    int c_tmp = 0;
    if(mod_color_score[mod][from] < 0) {
        
        // cerr << "calc score for (" << from << ", " << mod << ")" << endl;
        REP(x, N){
            REP(y, N){
                // cerr << "(x, y) = (" << x << ", " << y << "), c[y][x] = " << c[y][x] << " from = " << from << endl;
                if((x+y)%3 == mod) {
                    c_tmp += D[c[y][x]-1][from];
                }
            }
        }
        mod_color_score[mod][from] = c_tmp;
    } else {
        c_tmp = mod_color_score[mod][from];
    }

    bool remain = false;
    REP(mod_, 3) if(!mod_used[mod_]) remain = true;
    if(!remain){
        // cerr << "don't exec recursive call, c_tmp = " << c_tmp << endl;
        return mod_color_score[mod][from];
    }

    int d_sum = 1e9;
    bool call = false;

    REP(mod_, 3) {
        if(!mod_used[mod_]) {
            REP(color, C){
                if(!color_used[color]) {
                    int d_sum_tmp = dfs(color, mod_, color_used, mod_used, D, c, mod_color_score);
                    if(d_sum > d_sum_tmp) {
                        // cerr << "d_sum_tmp = " << d_sum_tmp << endl;
                        d_sum = d_sum_tmp;
                        call = true;
                    }
                }
            }
        }
    }

    // if(!call) d_sum = 0;
    // cerr << "c_tmp = " << c_tmp << " d_sum = " << d_sum << endl;
    return c_tmp + d_sum;
}

int main() {
    cin >> N >> C;
    vector< vector<int> > D(C, vector<int>(C)), c(N, vector<int>(N)), mod_color_score(3, vector<int>(C, -1));
    REP(i, C) REP(j, C) cin >> D[i][j];
    REP(i, N) REP(j, N) cin >> c[i][j];

    vector<bool> color_used(C, false), mod_used(3, false);

    int ans = 1e9;
    REP(color, C) {
        REP(mod, 3) {
            int tmp = dfs(color, mod, color_used, mod_used, D, c, mod_color_score);
            if(tmp < ans) ans = tmp; 
        }
    }

    cout << ans << endl;

    return 0;
}