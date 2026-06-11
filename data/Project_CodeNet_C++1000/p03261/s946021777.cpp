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
    ll N;
    cin >> N;

    vector<string> W(N);
    REP(i, N) {
        cin >> W[i];
    }

    FOR(i, 1, W.size()) {
        char shiri = W[i - 1][W[i - 1].length() - 1];
        if(W[i][0] != shiri) {
            cout << "No" << endl;
            return 0;
        }

        REP(j, i) {
            if(W[i] == W[j]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}