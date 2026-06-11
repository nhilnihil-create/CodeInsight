#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define ARRAY_LENGTH(array) sizeof(array)/sizeof(*array)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const int INF = 1000100100;

ll A, B;

int main() {
    cin >> A >> B;

    ll ans = 0;
    for(ll n = A; n <= B; ++n) {
        string ns = to_string(n);
        if(ns[0] == ns[4] && ns[1] == ns[3]) {
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}