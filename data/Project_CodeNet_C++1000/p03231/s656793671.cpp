#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i = 0; i < n; i++)
#define Rep(i,n) for(ll i = 1; i <= n; i++)
#define sz(x) ll(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl '\n'
#define fi first
#define se second
using ll = long long;
using P = pair<ll,ll>;
using Pl = pair<ll,ll>;
template<class T> using V = vector<T>;
const ll dx[] = {0,1,0,-1,1,1,-1,-1};
const ll dy[] = {1,0,-1,0,1,-1,-1,1};
const ll inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll &a, const ll &b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll gcd(ll a, ll b) {
    if(a%b == 0) return b;
    return gcd(b, a%b);
}

int main(){
    ll n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    ll g = gcd(n,m);
    ll l = 1LL*n/g*m;
    n /= g; m /= g;
    bool ok = true;
    for(ll i = 0; i < g; i++) {
        if(s[i*n] != t[i*m]) ok = false;
    }
    if(ok) cout << l << endl;
    else cout << -1 << endl;
}