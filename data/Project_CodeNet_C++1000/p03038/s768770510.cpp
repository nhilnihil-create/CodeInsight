#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<int> a(n);
    bool flag = true;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<pair<int,int>> p(m);
    for (int i = 0; i < m; i++) {
        int b, c;
        cin >> b >> c;
        p.push_back({c,b});
    }
    sort(p.rbegin(), p.rend());
    for (int i = 0; i < p.size(); i++) {
        int c = p[i].first, b = p[i].second;
        for (int j = 0; j < b; j++) {
            if (a[0] >= c) {
                break;
                flag = false;
            }
            a.erase(a.begin());
            a.push_back(c);
        }
        if (flag == false) break;
    }
    ll ans = 0;
    for (int i = 0; i < a.size(); i++) {
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
}