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
const int inf = 1<<30;
const ll inf_l = 1LL<<61;
const int MAX = 1e5;

int main() {
    int l; cin >> l;
    vector<tuple<int,int,int>> ans;
    rep(i,18) {
        ans.emplace_back(i + 1, i + 2, 0);
        ans.emplace_back(i + 1, i + 2, 1 << i);
    }
    bool exception = false;
    if (l >= (1 << 19)) {
        ans.emplace_back(19, 20, 0);
        ans.emplace_back(19, 20, 1 << 18);
        exception = true;
        l -= 1 << 19;
    }
    int sum = exception ? 1 << 19 : 0;
    rep(i,20) {
        if (l >> i & 1) {
            ans.emplace_back(i + 1, 20, sum);
            sum += 1 << i;
        }
    }
    cout << 20 << " " << (int)ans.size() << endl;
    rep(i,ans.size()) {
        int u, v, c;
        tie(u, v, c) = ans[i];
        cout << u << " " << v << " " << c << endl;
    }
}