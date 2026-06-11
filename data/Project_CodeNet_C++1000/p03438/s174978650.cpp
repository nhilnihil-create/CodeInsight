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
const int inf = 1e9+7;
const ll inf_l = 1e18;
const int MAX = 1e6;

int main() {
    int n; cin >> n;
    vint a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    ll ct_a = 0, ct_b = 0;
    rep(i,n) {
        if (a[i] > b[i]) ct_b += a[i] - b[i];
        if (a[i] < b[i]) ct_a += (b[i]-a[i])/2;
    }
    if (ct_b <= ct_a) cout << "Yes" << endl;
    else cout << "No" << endl;
}