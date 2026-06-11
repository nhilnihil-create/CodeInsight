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

//最大公約数と最小公倍数
ll gcd(ll a, ll b) {return(b?gcd(b,a%b):a);}
ll lcm(ll a, ll b) {return(a/gcd(a,b)*b);}

int main() {
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    ll g = lcm(n,m);
    ll h = lcm(g/n,g/m);
    bool ok = true;
    for (ll i = 0; i <= min((m-1)*(g/m),(n-1)*(g/n)); i += h) {
        if (s[i/(g/n)] != t[i/(g/m)]) ok = false;
    }
    if (ok) cout << g << endl;
    else cout << -1 << endl;
}