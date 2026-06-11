#include <bits/stdc++.h>

#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define ACC(c) (accumulate(ALL(c), 0LL))
#define PRINT(x) cout << (x) << "\n"

using namespace std;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;

inline int std_in(int& a) {return scanf("%d", &a);}
auto pint_compare = [](pint x, pint y) -> bool{return (x.first < y.first);};
const int MOD = 1000000007;

signed main(){
    ll N, K;
    cin >> N >> K;
    ll ans = (N / K) * (N / K) * (N / K);
    if(K % 2 == 0){
        ans += ((N + K / 2) / K) * ((N + K / 2) / K) * ((N + K / 2) / K);
    }
    PRINT(ans);
    return 0;
}