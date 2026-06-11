#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

signed main(){
    ll N, K;
    cin >> N >> K;
    double ans = 0, d = 0.5;
    FOR(i, 1, N + 1){
        ans += pow(0.5, ceil(max(0.0, log2((K + i - 1) / i))));
        if(i <= 100) cerr << ans << endl;
    }
    ans /= N;
    printf("%.9f\n", ans);
    return 0;
}