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
const int MAX = 2*1e5;

int n;
vint ans;

void dfs(vint b, vint tmp_ans) {
    if (b.empty()) {
        reverse(all(tmp_ans));
        ans = tmp_ans;
        return;
    }
    int n = b.size();
    for (int i = n; i >= 1; i--) {
        if (b[i-1] == i) {
            tmp_ans.push_back(i);
            b.erase(b.begin()+i-1);
            dfs(b,tmp_ans);
            break;
        }
    }
}

int main() {
    cin >> n;
    vint b(n);
    rep(i,n) cin >> b[i];
    dfs(b,vint {});
    if (ans == vint {}) cout << -1 << endl;
    else rep(i,n) cout << ans[i] << endl;
}