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
    ll N, M;
    cin >> N >> M;

    vector<ll> L(M), R(M);
    REP(i, M) {
        cin >> L[i] >> R[i];
    }

    ll minID = 1, maxID = N;
    REP(i, M) {
        if(L[i] > minID) {
            minID = L[i];
        } 

        if(R[i] < maxID) {
            maxID = R[i];
        }
    }

    if(maxID - minID >= 0) {
        cout << maxID - minID + 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}