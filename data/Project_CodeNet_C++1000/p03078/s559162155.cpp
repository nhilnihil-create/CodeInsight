#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<ll> a(x), b(y), c(z);
    rep(i, x)cin >> a[i];
    rep(i, y)cin >> b[i];
    rep(i, z)cin >> c[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    ll l = 0;
    ll r = a[x-1] + b[y-1] + c[z-1] + 1;
    while(l + 1 < r){
        ll xx = (l + r) / 2;
        int cnt = 0;
        rep(i, x)rep(j, y){
            ll sum = a[i] + b[j];
            int nl = -1;
            int nr = z;
            while(nl + 1 < nr){
                int xxx = (nl + nr) / 2;
                ll zsum = sum + c[xxx];
                if(zsum >= xx)nr = xxx;
                else nl = xxx;
            }
            cnt += z - nr;
        }
        if(cnt > k)l = xx;
        else r = xx;
    }
    vector<ll> ans;
    rep(i, x)rep(j, y){
        ll sum = a[i] + b[j];
        rep(ii, z){
            ll zsum = sum + c[z-1-ii];
            if(zsum >= l)ans.push_back(zsum);
            else break;
        }
    }
    sort(ans.begin(), ans.end(), greater<ll>());
    rep(i, k)cout << ans[i] << endl;
}