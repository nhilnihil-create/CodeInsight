#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

using T = tuple<ll, ll, ll, ll>;

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
    map<T, int> mp;
    priority_queue<T> que;
    que.push(T(a[0] + b[0] + c[0], 0, 0, 0));
    for (int i = 0; i < k; i++) {
        T t = que.top(); que.pop();
        cout << get<0>(t) << endl;
        ll j = get<1>(t), l = get<2>(t), r = get<3>(t);
        if (j + 1 < x && mp[T(a[j + 1] + b[l] + c[r], j + 1, l, r)] == 0) {
            que.push(T(a[j + 1] + b[l] + c[r], j + 1, l, r));
            mp[T(a[j + 1] + b[l] + c[r], j + 1, l, r)]++;
        }
        if (l + 1 < y && mp[T(a[j] + b[l + 1] + c[r], j, l + 1, r)] == 0) {
            que.push(T(a[j] + b[l + 1] + c[r], j, l + 1, r));
            mp[T(a[j] + b[l + 1] + c[r], j, l + 1, r)]++;
        }
        if (r + 1 < z && mp[T(a[j] + b[l] + c[r + 1], j, l, r + 1)] == 0) {
            que.push(T(a[j] + b[l] + c[r + 1], j, l, r + 1));
            mp[T(a[j] + b[l] + c[r + 1], j, l, r + 1)]++;
        }
    }
}