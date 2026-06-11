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
    long double N, M, d;
    cin >> N >> M >> d;
    if(d == 0) printf("%.10Lf\n",(M - 1) / N);
    else printf("%.10Lf\n",(2 * (N - d) * (M - 1)) / (N * N));
    return 0;
}			