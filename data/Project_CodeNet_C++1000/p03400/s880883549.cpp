#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define ARRAY_LENGTH(array) sizeof(array)/sizeof(*array)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {
    ll N, D, X;
    cin >> N >> D >> X;

    vector<ll> A(N);
    REP(i, N) cin >> A[i];

    ll sum = X;
    REP(i, N) {
        for(ll j = 0; j*A[i] + 1 <= D; ++j) {
            ++sum;
        }
    }

    cout << sum << endl;

    return 0;
}