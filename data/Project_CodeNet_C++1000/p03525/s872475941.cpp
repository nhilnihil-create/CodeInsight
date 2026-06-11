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
    map<int,int> mp;
    mp[0] = 1;
    rep(i,n) {
        int x; cin >> x;
        mp[x]++;
    }
    bool corner = false;
    if (mp[0] >= 2 || mp[12] >= 2) corner = true;
    vint search;
    vint x;
    if (mp[0] == 1) x.push_back(0);
    if (mp[12] == 1) x.push_back(12);
    for (P p : mp) {
        if (p.second >= 3) corner = true;
        if (p.first == 0 || p.first == 12) continue;
        if (p.second == 1) search.push_back(p.first);
        if (p.second == 2) {
            x.push_back(p.first);
            x.push_back(24-p.first);
        }
    }
    if (corner) cout << 0 << endl;
    else {
        int n_ = search.size();
        int ans = 0;
        rep(i,1<<n_) {
            vint tmp = x;
            rep(j,n_) {
                if (i>>j&1) tmp.push_back(search[j]);
                else tmp.push_back((24-search[j])%24);
            }
            int diff = inf;
            rep(i,tmp.size())rep(j,i) {
                int diff_ = abs(tmp[i]-tmp[j]);
                diff = min(diff,min(diff_,24-diff_));
            }
            ans = max(diff,ans);
        }
        cout << ans << endl;
    }
}
