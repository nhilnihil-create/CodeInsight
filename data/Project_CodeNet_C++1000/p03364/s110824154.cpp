#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
template<typename T> auto compare = [](T x, T y) -> bool{return (x < y);};
const int MOD = 1000000007;

int N;
char S[1000][1000];
bool sym[1000][1000];

signed main(){
    cin >> N;
    REP(i, N) REP(j, N) cin >> S[i][j];
    REP(i, 2 * N) REP(j, 2 * N) S[i][j] = S[i % N][j % N];
    int ans = 0;
    REP(B, N){
        bool ok = true;
        REP(i, N){
            REP(j, N){
                if(S[i][B + j] != S[j][B + i]){
                    ok = false;
                    break;
                }
            }
            if(!ok) break;
        }
        if(ok) ans++;
    }
    PRINT(ans * N);
    return 0;
}