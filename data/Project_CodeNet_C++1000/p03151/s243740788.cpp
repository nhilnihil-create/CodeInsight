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

int main() {
    int n; cin >> n;
    vint a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    int ans = 0;
    ll diff = 0;
    vint x;
    rep(i,n) { 
        if (b[i] > a[i]) {
            ans++;
            diff += b[i] - a[i];
        } 
        if (a[i] > b[i]) x.push_back(a[i]-b[i]);
    }
    if (x.empty() && diff > 0) {cout << -1 << endl; return 0;}
    sort(rall(x));
    int id = 0;
    while (diff > 0 && id < (int)x.size()) {
        diff -= x[id++];
        ans++;
    }
    if (diff > 0) {cout << -1 << endl; return 0;}
    else cout << ans << endl;
}