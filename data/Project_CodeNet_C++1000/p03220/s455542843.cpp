#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define ARRAY_LENGTH(array) sizeof(array)/sizeof(*array)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const int INF = 1000100100;

int main() {
    ll N, T, A;
    cin >> N >> T >> A;

    ll ans = 1;
    long double min_dif = INF;
    REP(i, N) {
        ll H;
        long double tmp, tmp_dif;
        cin >> H;
        tmp = T - H*0.006;
        tmp_dif = abs(A - tmp);

        if(i == 0 || tmp_dif < min_dif) {
            min_dif = tmp_dif;
            ans = i + 1;
        }
    }
    cout << ans << endl;

    return 0;
}