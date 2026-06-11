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

    ll cnt0 = 0, cnt1 = 0;
    REP(i, S.length()) {
        if(i % 2 == 0) {
            if(S[i] != '0') {
                ++cnt0;
            }

            if(S[i] != '1') {
                ++cnt1;
            }
        } else {
            if(S[i] != '1') {
                ++cnt0;
            }

            if(S[i] != '0') {
                ++cnt1;
            }
        }
    }

    cout << min(cnt0, cnt1) << endl;

    return 0;
}