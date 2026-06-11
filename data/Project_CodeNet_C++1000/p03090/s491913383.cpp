#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
template<typename T> auto compare = [](T x, T y) -> bool{return (x < y);};
const int MOD = 1000000007;

signed main(){
    int N;
    cin >> N;
    PRINT(N * (N - 1) / 2 - N / 2);
    FOR(i, 1, N){
        FOR(j, i + 1, N + 1){
            if(N % 2 == 0 && i + j == N + 1) continue;
            if(N % 2 == 1 && i + j == N) continue;
            cout << i << " " << j << endl;
        }
    }
    return 0;
}