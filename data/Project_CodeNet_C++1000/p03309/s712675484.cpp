#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll N, A[200010];

signed main(){
    cin >> N;
    REP(i, N){
        cin >> A[i];
        A[i] -= i + 1;
    }
    sort(A, A + N);
    ll b = A[N / 2];
    ll ans = 0;
    REP(i, N) ans += abs(A[i] - b);
    PRINT(ans);
    return 0;
}