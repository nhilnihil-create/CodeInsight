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
    string S;
    cin >> N >> K >> S;
    S[K - 1] = 'a' + (S[K - 1] - 'A');
    PRINT(S);
    return 0;
}