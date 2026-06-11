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
    int n_a = 0, n_b = 0, n_ab = 0;
    int ans = 0;
    rep(i,n) {
        string s; cin >> s;
        if (s.back() == 'A' && s.front() == 'B') n_ab++;
        else if (s.back() == 'A') n_a++;
        else if (s.front() == 'B') n_b++;
        rep(j,s.size()-1) if (s.substr(j,2) == "AB") ans++;
    }
    ans += min(n_a,n_b);
    if (n_a != 0 || n_b != 0) ans += n_ab;
    else {
        if (n_ab != 0) ans += n_ab - 1; 
    }
    cout << ans << endl;
}