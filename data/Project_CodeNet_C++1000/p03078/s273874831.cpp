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
    vector<ll> vec;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            vec.push_back(a[i] + b[j]);
        }
    }
    sort(vec.begin(), vec.end());
    int idx[z];
    for (int i = 0; i < z; i++) idx[i] = vec.size() - 1;
    priority_queue<ll> que;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < z; j++) {
            if (idx[j] < 0) continue;
            que.push(vec[idx[j]] + c[j]);
            idx[j]--;
        }
    }
    for (int i = 0; i < k; i++) {
        cout << que.top() << endl;
        que.pop();
    }
}