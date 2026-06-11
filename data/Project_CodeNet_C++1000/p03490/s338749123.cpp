#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <array>
#include <vector>
#include <utility>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <stack>

using namespace std;

using ll = long long;
using p = pair<ll, ll>;

constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;

vector<ll> D;
bool dpx[8001][16001], dpy[8001][16001];

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    ll x, y;
    cin >> s;
    cin >> x >> y;

    for (ll i = 0, n = 0; i < s.size(); i++) {
        if (s[i] == 'F') {
            n++;
        } 
        if (s[i] == 'T' || i == s.size() - 1) {
            D.push_back(n);
            n = 0;
        }
    }

    dpx[0][8000] = dpy[0][8000] = true;
    dpx[1][D[0] + 8000] = true;

    for (ll i = 2; i <= D.size(); i++) {
        for (ll j = -8000; j <= 8000; j++) {
            if (i % 2 == 0) {
                dpx[i][j + 8000] = dpx[i - 1][j + 8000];
                continue;
            }

            bool b = false;
            if (j - D[i - 1] >= -8000) {
                b |= dpx[i - 1][j + 8000 - D[i - 1]];
            }
            if (j + D[i - 1] <= 8000) {
                b |= dpx[i - 1][j + 8000 + D[i - 1]];
            }
            dpx[i][j + 8000] = b;
        }
    }

    for (ll i = 1; i <= D.size(); i++) {
        for (ll j = -8000; j <= 8000; j++) {
            if (i % 2) {
                dpy[i][j + 8000] = dpy[i - 1][j + 8000];
                continue;
            }

            bool b = false;
            if (j - D[i - 1] >= -8000) {
                b |= dpy[i - 1][j + 8000 - D[i - 1]];
            }
            if (j + D[i - 1] <= 8000) {
                b |= dpy[i - 1][j + 8000 + D[i - 1]];
            }
            dpy[i][j + 8000] = b;
        }
    }

    if (dpx[D.size()][x + 8000] && dpy[D.size()][y + 8000]) {
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;
    return 0;
}

