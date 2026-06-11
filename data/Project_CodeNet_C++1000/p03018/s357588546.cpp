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
    string s; cin >> s;
    rep(i,s.size()) {
        if (s.substr(i,2) == "BC") s.replace(i,2,"D");
    }
    reverse(all(s));
    int len = 0;
    ll ans = 0;
    rep(i,s.size()) {
        if (s[i] == 'B' || s[i] == 'C') len = 0;
        else if (s[i] == 'D') len++;
        else if (s[i] == 'A') ans += len;
    }
    cout << ans << endl;
}