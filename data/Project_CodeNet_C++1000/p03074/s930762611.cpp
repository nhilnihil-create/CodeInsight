#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vec a;
    if (s[0] == '0') a.push_back(0);

    int cnt = 1;
    rep(i, n) {
        if (i == 0) continue;
        if (s[i-1] != s[i]) {
            a.push_back(cnt);
            cnt = 1;
        }
        else {
            cnt++;
        }
    }
    a.push_back(cnt);
    if (s[n-1] == '0') a.push_back(0);

    int res = 0;
    int v = a.size();

    vec as(v+1);
    rep(i, v) as[i+1] = as[i] + a[i];

    bool update = false;
    for (int i = 0; i + 2 * k + 1 <= v; i+=2) {
        res = max(res, as[i+2*k+1] - as[i]);
        if (!update) update = true;
    }

    if (!update) res = n;

    cout << res << endl;
    return 0;
}