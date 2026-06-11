#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define ARRAY_LENGTH(array) sizeof(array)/sizeof(*array)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {
    ll N, M, X;
    cin >> N >> M >> X;

    ll to0 = 0, toN = 0;
    vector<ll> A(M);
    REP(i, M) {
        cin >> A[i];
        if(A[i] < X) {
            ++to0;
        } else {
            ++toN;
        }
    }

    cout << min(to0, toN) << endl;

    return 0;
}