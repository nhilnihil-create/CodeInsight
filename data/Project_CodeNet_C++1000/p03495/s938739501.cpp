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
    vec a(n);
    rep(i, n) cin >> a[i];

    map<int, int> mp;
    rep(i, n) mp[a[i]]++;

    vector<P> type;
    for (auto&& p : mp) {
        int k = p.first, v = p.second;
        type.push_back({v, k});
    }

    sort(all(type));

    if (type.size() <= k) {
        cout << 0 << endl;
        exit(0);
    }
    
    lint res = 0;

    rep(i, type.size() - k) {
        res += type[i].first;
    }

    cout << res << endl;
    return 0;
}