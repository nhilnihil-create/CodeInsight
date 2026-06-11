#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
template<typename T> auto compare = [](T x, T y) -> bool{return (x < y);};
const int MOD = 1000000007;

int K;
ll A[100010], inf[100010], sup[100010];

signed main(){
    cin >> K;
    REP(i, K) cin >> A[i];
    if(A[K - 1] != 2){
        PRINT("-1");
        return 0;
    }
    inf[K] = 2; sup[K] = 2;
    for(int i = K - 1; i >= 0; i--){
        if(inf[i + 1] % A[i] != 0 && sup[i + 1] % A[i] != 0 && inf[i + 1] % A[i] < sup[i + 1] % A[i] && sup[i + 1] - inf[i + 1] < A[i]){
            PRINT("-1");
            return 0;
        }
        inf[i] = (inf[i + 1] + A[i] - 1) / A[i] * A[i];
        sup[i] = sup[i + 1] / A[i] * A[i] + A[i] - 1; 
    }
    cout << inf[0] << " " << sup[0] << endl;
    return 0;
}