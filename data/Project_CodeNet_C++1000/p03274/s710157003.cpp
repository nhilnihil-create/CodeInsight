#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> x(n);
    int fst_pl = -1;
    rep(i, n) {
        cin >> x[i];
        if (fst_pl == -1 && x[i] > 0) fst_pl = i;
    }

    ll ans = 1001001001;
    for (int i=0; i<n-k+1; i++) {
        ll tmp = abs(x[i] - x[i+k-1]);
        if (i < fst_pl && i+k-1 >= fst_pl) {
            ll s = min(abs(x[i]), x[i+k-1]);
            tmp += s;
        } else if (fst_pl >= i){
            tmp += abs(x[i]);
        } else {
            tmp += abs(x[i+k-1]);
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}