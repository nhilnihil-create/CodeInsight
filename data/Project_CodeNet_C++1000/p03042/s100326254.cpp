#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

signed main(){
    string S;
    cin >> S;
    ll s = 10 * (S[0] - '0') + (S[1] - '0');
    ll t = 10 * (S[2] - '0') + (S[3] - '0');
    bool M1 = (1 <= s && s <= 12);
    bool M2 = (1 <= t && t <= 12);
    if(M1 && M2) PRINT("AMBIGUOUS");
    else if(M1) PRINT("MMYY");
    else if(M2) PRINT("YYMM");
    else PRINT("NA");
    return 0;
}