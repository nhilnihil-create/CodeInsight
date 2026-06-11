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
    ll A, B, K;
    cin >> A >> B >> K;

    for(ll i = A; i <= min(A + K - 1, B); ++i) {
        cout << i << endl;
    }
    for(ll i = max(A + K, B - K + 1); i <= B; ++i) {
        cout << i << endl;
    }

    return 0;
}