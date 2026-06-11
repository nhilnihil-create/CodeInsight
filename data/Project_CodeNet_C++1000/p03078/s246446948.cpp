#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int x,y,z,k;
    cin >> x >> y >> z >> k;

    vector<ll> a(x),b(y),c(z);
    for (int i = 0; i < x; i++) cin >> a[i];
    for (int i = 0; i < y; i++) cin >> b[i];
    for (int i = 0; i < z; i++) cin >> c[i];

    vector<ll> ab;

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            ab.push_back(a[i] + b[j]);
        }
    }

    sort(ab.rbegin(),ab.rend());
    sort(c.rbegin(),c.rend());

    vector<ll> ans;
    for (int i = 0; i < min(k, (int)ab.size()); i++) {
        for (int j = 0; j < min(k, (int)c.size()); j++) {
            ans.push_back(ab[i] + c[j]);
        }
    }
    sort(ans.rbegin(),ans.rend());
    for (int i = 0; i < k; i++) cout << ans[i] << '\n';
}