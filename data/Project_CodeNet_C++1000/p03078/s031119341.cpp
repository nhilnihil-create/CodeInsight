#include <bits/stdc++.h>
#include <tuple>
typedef long long int ll;
using namespace std;
int main() {
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<ll> a;
    vector<ll> b;
    vector<ll> c;
    for (int i = 1; i <= x; i++) {
        ll p;
        cin >> p;
        a.push_back(p);
    }
    for (int i = 1; i <= y; i++) {
        ll n;
        cin >> n;
        b.push_back(n);
    }
    for (int i = 1; i <= z; i++) {
        ll q;
        cin >> q;
        c.push_back(q);
    }
    vector<ll> ab;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            ab.push_back(a[i] + b[j]);
        }
    }
    sort(ab.begin(), ab.end());
    sort(c.begin(), c.end());
    vector<ll> res;
    int S = ab.size();
    int T = c.size();
    int s = min(k, S);
    int t = min(k, T);
    for (int i = 1; i <= s; i++) {
        for (int j = 1; j <= t; j++) {
            res.push_back(ab[ab.size() - i] + c[c.size() - j]);
        }
    }
    sort(res.begin(), res.end());
    for (int i = 1; i <= k; i++) {
        cout << res[res.size() - i] << endl;
    }
    return 0;
}