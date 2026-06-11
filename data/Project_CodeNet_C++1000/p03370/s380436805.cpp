#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll oo = 1e9 + 10;
const ll mod = 998244353,maxn = 110;
const double PI = acos(-1); 

ll solve(ll a, ll b, ll cs, ll cw, ll s, ll w){

    ll ans = 0, cnt = 0, ans2 = 0;
    for (ll i=0; i<=cs; i++){
        if (i*s > a) break;
        ll tmp = i + min((a - i*s)/w, cw);
        if (tmp > ans) {
            ans = tmp, cnt = i;
        }
    }
    cs -= cnt;
    cw -= (ans - cnt);
    cnt = 0;

    for (ll i=0; i<=cs; i++){
        if (i*s > b) break;
        ll tmp = i + min((b - i*s)/w, cw);
        if (tmp > ans2) {
            ans2 = tmp, cnt = i;
        }
    }
    ans += ans2;
    return ans;
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, x, sum = 0, less = 1000000;
    cin >> n >> x;
    vector<int> v(n);

    for (auto &it: v) cin >> it, sum += it, less = min (less, it);

    cout << (x - sum)/less + n << endl;
    return 0; 
}