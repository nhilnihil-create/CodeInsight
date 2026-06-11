#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    ll a[x], b[y], c[z];
    for (int i = 0; i < x; i++) cin >> a[i];
    for (int i = 0; i < y; i++) cin >> b[i];
    for (int i = 0; i < z; i++) cin >> c[i];
    priority_queue<ll> que, ans;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            que.push(a[i] + b[j]);
        }
    }
    sort(c, c + z, greater<ll>());
    for (int i = 0; i < k && !que.empty(); i++) {
        ll t = que.top(); que.pop();
        for (int j = 0; j < min(k, z); j++) {
            ans.push(t + c[j]);
        }
    }
    for (int i = 0; i < k; i++) {
        cout << ans.top() << endl;
        ans.pop();
    }
}