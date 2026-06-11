#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

constexpr long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    map<int, int> mp;
    rep(i, n) {
        int t;
        cin >> t;
        if (mp.count(t)) {
            mp[t]++;
        } else {
            mp[t] = 1;
        }
    }

    int cnt = 0;
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        if (itr->first <= itr->second) {
            cnt += itr->second - itr->first;
        } else {
            cnt += itr->second;
        }
    }

    cout << cnt << endl;
}