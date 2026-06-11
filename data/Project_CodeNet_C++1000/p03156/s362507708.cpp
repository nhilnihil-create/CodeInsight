#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

signed main(){
    ll N, A, B, P;
    cin >> N >> A >> B;
    ll x = 0, y = 0, z = 0;
    REP(i, N){
        cin >> P;
        if(P <= A) x++;
        else if(P <= B) y++;
        else z++;
    }
    PRINT(min(x, min(y, z)));
    return 0;
}