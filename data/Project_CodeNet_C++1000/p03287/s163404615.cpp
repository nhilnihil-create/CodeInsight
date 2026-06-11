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

lint choose2(lint n) {
    return n * (n-1) / 2;
}

int main() {
    int n, m;
    cin >> n >> m;
    vec a(n);
    rep(i, n) cin >> a[i];

    vector<lint> s(n+1);
    rep(i, n) s[i+1] = (s[i] + a[i]) % m;

    map<int, int> mp;
    rep(i, n+1) mp[s[i]]++;

    lint res = 0;

    for (auto&& p : mp) {
        lint v = p.second;
        res += choose2(v);
    }

    cout << res << endl;
    return 0;
}