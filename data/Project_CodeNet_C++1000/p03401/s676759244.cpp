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

    vll a;
    a.push_back(0);
    rep(i, n) {
        ll t;
        cin >> t;
        a.push_back(t);
    }
    a.push_back(0);

    ll sum = 0;
    rep(i, n + 1) {
        sum += abs(a[i + 1] - a[i]);
    }

    for (int i = 1; i <= n; i++) {
        cout << sum + abs(a[i - 1] - a[i + 1]) - (abs(a[i - 1] - a[i]) + abs(a[i] - a[i + 1])) << endl;
    }
}