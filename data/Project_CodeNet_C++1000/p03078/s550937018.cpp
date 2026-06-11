#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<ll> a(x);
    for (int i = 0; i < x; i++) {
        cin >> a[i];
    }
    vector<ll> b(y);
    for (int i = 0; i < y; i++) {
        cin >> b[i];
    }
    vector<ll> c(z);
    for (int i = 0; i < z; i++) {
        cin >> c[i];
    }
    vector<ll> sums_ab;
    for (auto aa: a) {
        for (auto bb: b) {
            sums_ab.emplace_back(aa + bb);
        }
    }
    sort(sums_ab.begin(), sums_ab.end(), greater<ll>());
    vector<ll> sums;
    for (int i = 0; i < min(k, (int)sums_ab.size()); i++) {
        for (int l = 0; l < z; l++) {
            sums.emplace_back(sums_ab[i] + c[l]);
        }
    }
    sort(sums.begin(), sums.end(), greater<ll>());
    for (int i = 0; i < k; i++) {
        cout << sums[i] << endl;
    }
    return 0;
}
