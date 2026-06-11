#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using PP = pair<int,int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    rep(i,n) {
        cin >> a[i] >> b[i];
    }
    vector<PP> ab(n);
    rep(i,n) {
        ab[i] = make_pair(a[i], b[i]);
    }
    sort(ab.begin(), ab.end());

    ll cost = 0;
    rep(i,n) {
        int buy = min(m, ab[i].second);
        cost += (ll)buy * ab[i].first;
        m -= buy;
    }
    cout << cost << endl;

    return 0;
}