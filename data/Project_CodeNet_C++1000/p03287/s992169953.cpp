#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const ll inf = 1e18;
const int mod = 1e5;
const int MAX = 1e6;

int main() {
    int n, m;
    cin >> n >> m;
    vll a(n);
    vll c(n+1,0);
    unordered_map<ll,ll> ct;
    rep(i,n) cin >> a[i];
    ct[0]++;
    REP(i,n+1) {
        c[i] = (c[i-1] + a[i-1]) % m;
        ct[c[i]]++;
    }
    ll ans = 0;
    for (auto pt = ct.begin(); pt != ct.end(); pt++) {
        ll x = pt->second;
        ans += x*(x-1)/2;
    }
    cout << ans << endl;
}