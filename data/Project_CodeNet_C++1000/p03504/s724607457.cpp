#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
template<typename T> auto compare = [](T x, T y) -> bool{return (x < y);};
const int MOD = 1000000007;

int N, C;
int rec[100010][30];

signed main(){
    cin >> N >> C;
    int s, t, c;
    REP(i, N){
        cin >> s >> t >> c;
        c--;
        FOR(i, s - 1, t){
            rec[i][c] = 1;
        }
    }
    int ans = 0;
    REP(i, 100010){
        int use = 0;
        REP(j, C){
            if(rec[i][j]) use++;
        }
        ans = max(ans, use);
    }
    PRINT(ans);
    return 0;
}