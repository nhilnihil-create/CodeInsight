#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vs = vector<string>;
using pll = pair<ll, ll>;
using vp = vector<pll>;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, a, b) for (ll i = (a); i < (b); i++)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((int)(x).size())
#define PRINT(V) for (auto v:(V)) {cerr << v << " ";} cerr << endl
#define dump(x) cerr << #x << " : " << (x) << endl
#define dump2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
const ll MOD = 1000000007;
const ll INF = 100000000000000000LL;
inline ll GCD(ll a, ll b){return b ? GCD(b, a % b) : a;}
inline ll LCM(ll a, ll b){return a / GCD(a, b) * b;}
inline ll powint(ll x, ll y){ll r=1;while(y){if(y&1)r*=x;x*=x;y>>=1;}return r;}
inline ll powmod(ll x, ll y, ll m = MOD){ll r=1;while(y){if(y&1)r*=x;x*=x;r%=m;x%=m;y>>=1;}return r;}
/* END OF TEMPLATE */

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll n;
    cin >> n;
    string a;
    cin >> a;
    string b;
    cin >> b;
    string c;
    cin >> c;
    ll ans = 0;
    rep(i, n){
        if(a[i] == b[i] && b[i] == c[i]){
            continue;
        }else if(a[i] == b[i] || b[i] == c[i] || c[i] == a[i]){
            ans++;
        }else{
            ans += 2;
        }
    }
    cout << ans << endl;
    return 0;
}