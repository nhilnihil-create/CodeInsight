#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, ll> freq;
int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> vec;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        vec.push_back(x);
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < m; i++) {
        int b, c;
        cin >> b >> c;
        freq[-c] += b;
    }
    int idx = 0;
    for (auto it: freq) {
        if (idx >= n) break;
        int tmp = it.second;
        while (idx < n && vec[idx] >= -it.first) idx++;
        while (tmp > 0 && idx < n && vec[idx] < -it.first) {
            vec[idx] = -it.first;
            idx++;
            tmp--;
        }
    }
    ll res = 0;
    for (auto x: vec) res += x;
    cout << res;
    return 0;
}