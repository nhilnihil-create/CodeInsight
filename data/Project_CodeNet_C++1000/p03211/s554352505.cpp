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
    string S;
    cin >> S;

    ll ans = INF;
    for(ll i = 0; i + 2 < S.length(); ++i) {
        ll tmp = stoi(S.substr(i, 3));
        if(abs(753 - tmp) < ans) {
            ans = abs(753 - tmp);
        }
    }

    cout << ans << endl;

    return 0;
}