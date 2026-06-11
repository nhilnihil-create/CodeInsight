#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool compare(const pair<ll, bool> &i, const pair<ll, bool> &j) {
    return i.first > j.first;
}

void solve() {
    ll n, B, a, b, count = 0, sum = 0;
    cin >> n >> B;
    vector<pair<ll, bool> > vc;
    for (ll i = 1; i <= n; i++) {
        cin >> a >> b;
        vc.push_back({b, true});
        vc.push_back({a, false});
    }
    sort(vc.begin(), vc.end(), compare);
    for (ll i = 0; i < vc.size(); i++) {
        if (sum >= B)break;
        if (vc[i].second == true) {
            sum += vc[i].first;
            count++;
        }
        else {
            ll left = B - sum;// 276=46
            if (left % vc[i].first == 0)count += ((left / vc[i].first));
            else count += (left / vc[i].first) + 1;
            break;
        }
    }
    cout << count << endl;
}

int32_t main() {
    ll t = 1;
    while (t--)
        solve();
    return 0;
}