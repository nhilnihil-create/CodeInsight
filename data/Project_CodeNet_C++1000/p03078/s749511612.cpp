#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int x, y, z, k;
ll a[1111], b[1111], c[1111];

bool f(ll n) {
    int cnt = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int l = 0; l < z; l++) {
                if (a[i] + b[j] + c[l] < n) break;
                cnt++;
                if (cnt >= k) return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> x >> y >> z >> k;
    for (int i = 0; i < x; i++) cin >> a[i];
    for (int i = 0; i < y; i++) cin >> b[i];
    for (int i = 0; i < z; i++) cin >> c[i];
    sort(a, a + x, greater<ll>());
    sort(b, b + y, greater<ll>());
    sort(c, c + z, greater<ll>());
    ll lb = -1, ub = 1001001001001;
    while (ub - lb > 1) {
        ll md = (ub + lb) / 2;
        if (f(md)) lb = md;
        else ub = md;
    }
    priority_queue<ll> que;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int l = 0; l < z; l++) {
                if (a[i] + b[j] + c[l] < lb) break;
                que.push(a[i] + b[j] + c[l]);
            }
        }
    }
    for (int i = 0; i < k; i++) {
        if (que.empty()) {
            cout << lb << endl;
        } else {
            cout << que.top() << endl;
            que.pop();
        }
    }
}