#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <utility>
#include <vector>
#include <complex>
#include <valarray>
#include <fstream>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <numeric>
#include <climits>
#include <random>

#define _overload(a, b, c, d, ...) d
#define _rep1(X, A, Y) for (int (X) = (A);(X) <= (Y);++(X))
#define _rep2(X, Y) for (int (X) = 0;(X) < (Y);++(X))
#define rep(...) _overload(__VA_ARGS__, _rep1, _rep2)(__VA_ARGS__)
#define rrep(X, Y) for (int (X) = Y-1;(X) >= 0;--(X))
#define all(X) (X).begin(),(X).end()
#define len(X) ((int)(X).size())
#define mod(n, m) (((n)%(m)+(m))%(m))
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;
const int INFINT = 1 << 30;                          // 1.07x10^ 9
const ll INFLL = 1LL << 60;                          // 1.15x10^18
const double EPS = 1e-10;
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

string S;
bool used[26];

int main() {
    cin >> S;

    if (S == "zyxwvutsrqponmlkjihgfedcba") {
        cout << -1 << endl;
        return 0;
    }

    if (len(S) < 26) {
        string ans = S;
        rep(i, len(S)) {
            used[S[i] - 'a'] = true;
        }
        rep(i, 26) {
            if (!used[i]) {
                char ch = i + 'a';
                ans += string{ch};
                break;
            }
        }
        cout << ans << endl;
        return 0;
    }

    rrep(i, 26) {
        used[S[i] - 'a'] = true;
        for (int j = S[i] - 'a' + 1; j < 26; ++j) {
            if (used[j]) {
                char ch = 'a' + j;
                string ans = S.substr(0, i) + string{ch};
                cout << ans << endl;
                return 0;
            }
        }
    }


    return 0;
}
