#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (a); i > (b); i--)
#define ALL(a) (a).begin(), (a).end()

bool check(vector<int> vi, int n) {
    bool dp[2][20000];
    bool *prev = dp[0], *next = dp[1];
    fill(prev, prev + 20000, false);
    fill(next, next + 20000, false);
    prev[vi[0] + 10000] = true;
    FOR(i, 1, vi.size()) {
        REP(j, 20000) {
            if (prev[j]) {
                next[j + vi[i]] = true;
                next[j - vi[i]] = true;
                prev[j] = false;
            }
        }
        swap(prev, next);
    }
    return prev[n + 10000];
}

int main() {
    string s;
    int x, y;
    cin >> s >> x >> y;

    s += 'T';
    vector<int> hv, vv;
    int count = 0;
    bool horizontal = true;
    REP(i, s.length()) {
        if (s[i] == 'T') {
            if (count > 0) {
                if (horizontal) hv.push_back(count);
                else vv.push_back(count);
            }
            horizontal = !horizontal;
            count = 0;
        }
        else count++;
    }

    bool okh = false, okv = false;
    if (hv.size() == 0) okh |= x == 0;
    else {
        okh |= check(hv, x);
        if (s[0] == 'T') {
            hv[0] *= -1;
            okh |= check(hv, x);
        }
    }
    if (vv.size() == 0) okv |= y == 0;
    else {
        okv |= check(vv, y);
        vv[0] *= -1;
        okv |= check(vv, y);
    }

    if (okh && okv) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}