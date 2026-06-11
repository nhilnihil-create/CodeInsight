#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <list>
#include <iomanip>
#include <queue>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;
template<class T>bool chmax(T & a, const T & b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T & a, const T & b) { if (b < a) { a = b; return 1; } return 0; }

int main() {

    string S;
    cin >> S;

    ll N = S.size();
    vector<ll> s(26);

    rep(i, N) {
        s[S[i] - 'a'] = i + 1;
    }

    if (N != 26) {
        char tale;
        rep(i, 26) {
            if (s[i] == 0) {
                tale = 'a' + i;
                break;
            }
        }
        cout << S + tale;
    }
    else {
        for (int i = 25; 0 <= i; i--) {
            if (S[i] < S[i + 1]) {
                char mn = S[i + 1];
                for (int j = i + 1; j < 26; j++) {
                    if (S[j] > S[i]) chmin(mn, S[j]);
                }
                cout << S.substr(0, i) + mn;
                return 0;
            }
        }
        cout << -1;
    }

    return 0;
}
