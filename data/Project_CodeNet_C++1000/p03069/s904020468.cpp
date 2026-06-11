#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define debug(var) do{cout << #var << " : "; view(var);}while(0)
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
template<class T> void view(T e) {cout << e << endl;}
template<class T> void view(const vector<T> &v) {for(const auto &e : v){cout << e << " ";} cout << endl;}
template<class T> void view(const vector<vector<T>> &vv) {for(const auto &v : vv){view(v);}}
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
    string s; cin >> s;
    vint accum_w(n+1,0), accum_b(n+1,0);
    REP(i,n+1) {
        accum_w[i] = accum_w[i-1];
        accum_b[i] = accum_b[i-1];
        if (s[i-1] == '.') accum_w[i]++;
        if (s[i-1] == '#') accum_b[i]++;
    }
    int ans = inf;
    rep(i,n+1) {
        ans = min(ans,accum_b[i]+accum_w[n]-accum_w[i]);
    }
    cout << ans << endl;
}