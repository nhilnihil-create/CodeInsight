#define _USE_MATH_DEFINES
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
#include <cmath>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
const long long mod = 1e9 + 7;
ll dx[] = { 1,0 };
ll dy[] = { 0,1 };

int main() {

    string S, T;

    cin >> S >> T;

    ll N = S.size(), M = T.size(), cnt, key;
    bool judge = false;

    rep(i, N - M + 1) {
        cnt = 0;
        rep(j, M) {
            if (T[j] == S[i + j] || S[i + j] == '?') {
                cnt++;
            }
        }
        if (cnt == M) {
            judge = true;
            key = i;
        }
    }

    
    if (judge) {
        string ans = "";
        ll i = 0;
        while (ans.size() != N) {
            if (i == key) {
                ans += T;
                i += M;
            }
            else {
                if (S[i] != '?') ans += S[i];
                else ans += 'a';
                i++;
            }
        }
        cout << ans;
    }
    else {
        cout << "UNRESTORABLE";
    }

    return 0;
}