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
    sort(a, a + x, greater<ll>());
    sort(b, b + y, greater<ll>());
    sort(c, c + z, greater<ll>());
    priority_queue<ll> que;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int l = 0; l < z; l++) {
                if ((i + 1) * (j + 1) * (l + 1) <= k) que.push(a[i] + b[j] + c[l]);
                else break;
            }
        }
    }
    for (int i = 0; i < k; i++) {
        cout << que.top() << endl;
        que.pop();
    }
}