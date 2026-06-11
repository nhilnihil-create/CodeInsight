#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define endl "\n"
#define rep(i, a, n) for (int i = a; i < n; ++i)
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> p(n);
    rep(i, 0, n) cin >> p[i];

    vector<int> cnt(3, 0);
    rep(i, 0, n) {
        if (p[i] <= a) cnt[0]++;
        else if (p[i] <= b) cnt[1]++;
        else cnt[2]++;
    }
    cout << min(min(cnt[0], cnt[1]), cnt[2]) << endl;
    return 0;
}
