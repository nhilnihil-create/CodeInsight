#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(ll i=ll(x);i<(ll)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7 
#define LONFINF 1e16
using ll = long long;
using P = pair<ll, ll>;
using lP = pair<ll, ll>;
using fP = pair<double, double>;
ll const mod = 998244353;
const ll MAX = 300000;
using vi = vector<ll>;
using vc = vector<char>;
using vs = vector<string>;
using vvi = vector<vector<ll>>;
using vvc = vector<vector<char>>;
using vvp = vector<vector<P>>;
int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll>x, y;
    y.push_back(0);
    rep(i, n) {
        ll a;
        cin >> a;
        if (a < 0)x.push_back(-a);
        else y.push_back(a);
    }

    x.push_back(0);//bannpei
    sort(x.begin(), x.end());
    int ms = min(k, (ll)y.size()-1);
    ll ans = LONFINF;
    for (int i = ms; i >= 0; i--) {
        if (k - i >= x.size())break;
        ans = min(ans, 2*y[i] + x[k - i]);
        ans = min(ans, 2 * x[k - i] + y[i]);
    }
    cout << ans << endl;
    return 0;
}