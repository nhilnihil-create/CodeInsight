#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i,n) for (int i = 0; i < (n); ++i)
int n, m;
int main() {
    cin >> n >> m;
    vector<tuple<ll, ll, ll>> xyz(n);
    rep(i, n) {
        ll x, y, z;
        cin >> x >> y >> z;
        xyz[i] = make_tuple(x, y, z);
    }
    vector<ll> num;
    ll tmp_num = 0;
    ll tmp_ans = 0;
    ll ans = 0;
    rep(i, (1<<3)) {
        tmp_ans = 0;
        num.clear();
        rep(j, n) {
            tmp_num = 0;
            if ( i & (1<<0) ) tmp_num += get<0>(xyz[j]);
            else              tmp_num -= get<0>(xyz[j]);
            if ( i & (1<<1) ) tmp_num += get<1>(xyz[j]);
            else              tmp_num -= get<1>(xyz[j]);
            if ( i & (1<<2) ) tmp_num += get<2>(xyz[j]);
            else              tmp_num -= get<2>(xyz[j]);
            num.push_back(tmp_num);
        }
        sort(num.begin(), num.end());
        rep(j, m) tmp_ans += num[m-1-j];
        ans = max(ans, abs(tmp_ans));
    }
    cout << ans << endl;
    return 0;
}