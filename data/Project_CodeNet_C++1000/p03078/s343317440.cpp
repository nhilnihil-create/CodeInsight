#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;
const int mod = 1e9+7;

vll sum_bc;
vll a, b, c;

bool check(ll x, int k) {
    int num = 0;
    rep(i,a.size()) {
        num += sum_bc.end()-lower_bound(all(sum_bc),x-a[i]);
    }
    return num >= k;
}

int main() {
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    a.resize(x); b.resize(y); c.resize(z);
    rep(i,x) cin >> a[i];
    rep(i,y) cin >> b[i];
    rep(i,z) cin >> c[i];
    rep(i,y)rep(j,z) sum_bc.push_back(b[i]+c[j]);
    sort(all(sum_bc));
    ll l = 0;
    ll r = inf_l;
    while (r-l > 1) {
        ll mid = (r+l)/2;
        if (check(mid,k)) l = mid;
        else r = mid;
    }
    vll ans_tmp;
    rep(i,x) {
        ll search = l - a[i];
        for (auto ptr = lower_bound(all(sum_bc),search); ptr != sum_bc.end(); ptr++) {
            ans_tmp.push_back(*ptr+a[i]);
        }
    }
    sort(rall(ans_tmp));
    vll ans;
    ans.assign(ans_tmp.begin(),ans_tmp.begin()+k);
    rep(i,ans.size()) printf("%lld\n",ans[i]);
}