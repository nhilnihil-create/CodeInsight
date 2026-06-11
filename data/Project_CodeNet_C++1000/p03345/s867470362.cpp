#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define ARRAY_LENGTH(array) sizeof(array)/sizeof(*array)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const int INF = 1000100100;

int main() {
    ll K, A, B, C;
    cin >> A >> B >> C >> K;

    ll ans = (A - B)*pow(-1, (K % 2));
    if(ans > 1e18) {
        cout << "Unfair" << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}