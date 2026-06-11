#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
template<typename T> auto compare = [](T x, T y) -> bool{return (x < y);};
const int MOD = 1000000007;

int N, M, Q;
int L[200010], R[200010];
int acc[505][505];

signed main(){
    cin >> N >> M >> Q;
    REP(i, M){
        cin >> L[i] >> R[i];
        acc[L[i]][R[i]]++;
    }
    REP(i, N){
        REP(j, N){
            acc[i + 1][j + 1] += acc[i + 1][j] + acc[i][j + 1] - acc[i][j];
        }
    }
    int p, q;
    REP(i, Q){
        cin >> p >> q;
        PRINT(acc[q][q] - acc[p - 1][q] - acc[q][p - 1] + acc[p - 1][p - 1]);
    }
    return 0;
}