#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int long long
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

signed main() {
    int n;
    cin >> n;
    int a[n];
    map<int, int> mp;
    rep (i, 0, n) {
        cin >> a[i];
        mp[a[i]]++;
    }
    int ans = 0;
    for (auto i : mp) {
        if (i.first < i.second) {
            ans += i.second - i.first;
        } else if (i.first > i.second) {
            ans += i.second;
        }
    }
    cout << ans << "\n";
}
