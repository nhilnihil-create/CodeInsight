#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vll = vector<long long>;

constexpr long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<pair<int, int>> idx;

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            int t = i;
            int cnt = 0;
            while (s[i] == '0') {
                cnt++;
                i++;
            }

            idx.push_back(make_pair(t, cnt));
        }
    }
    idx.push_back(make_pair(n, 0));

    int ans = 0;
    if (idx.size() <= k + 1) {
        ans = n;
    } else {
        int p = 0;
        for (int i = 0; i < idx.size() - k; i++) {
            ans = max(ans, idx[i + k].first - p);

            p = idx[i].first + idx[i].second;
        }
    }

    cout << ans << endl;
}