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

bool palindrome(string s) {
    string tmp = s;
    reverse(all(tmp));
    return s == tmp;
}

int main() {
    string s; cin >> s;
    int n = s.size();
    string s_;
    rep(i,n) {
        if (s[i] != 'x') s_ += s[i];
    }
    if (palindrome(s_)) {
        s += '.';
        int n_x = 0;
        vint n_xs;
        rep(i,n+1) {
            if (s[i] == 'x') n_x++;
            else {
                n_xs.push_back(n_x);
                n_x = 0;
            }
        }
        int n_ = n_xs.size();
        int ans = 0;
        for (int i = 0; i < n_/2; i++) {
            ans += max(n_xs[i],n_xs[n_-i-1]) - min(n_xs[i],n_xs[n_-i-1]);
        }
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
}