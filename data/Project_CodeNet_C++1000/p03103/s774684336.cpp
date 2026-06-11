#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
    int n, m;
    ll a, b;
    ll sum = 0;
    vector<pair<ll,ll>>enagy;
    cin >> n >> m;
    rep(i, n) {
        cin >> a >> b;
        enagy.push_back(make_pair(a, b));
    }
    sort(all(enagy));
    for (auto e : enagy) {
        if (e.second <= m) {
            m -= e.second;
            sum += e.first * e.second;
        }
        else {
            sum += e.first * m;
            break;
        }
    }
    cout << sum << endl;

}
