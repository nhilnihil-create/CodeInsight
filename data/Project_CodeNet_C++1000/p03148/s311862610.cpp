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
    int n, k; cin >> n >> k;
    vector<P> data(n);
    rep(i,n) {
        int t, d; cin >> t >> d;
        t--;
        data[i] = P(d,t);
    }
    sort(rall(data));
    vint num(n,0);
    ll value = 0;
    int id = k - 1;
    int n_kind = 0;
    rep(i,k) {
        value += data[i].first;
        if (num[data[i].second]++ == 0) n_kind++;
    }
    value += (ll)n_kind * n_kind;
    ll ans = value;
    for (int i = k; i < n; i++) {
        if (num[data[i].second] != 0) continue;
        for (int j = id; j >= -1; j--) {
            if (num[data[j].second] > 1 || j == -1) {
                id = j;
                break;
            }
        }
        if (id == -1) break;
        value += data[i].first + 2*n_kind + 1 - data[id].first;
        n_kind++;
        num[data[i].second]++;
        num[data[id].second]--;
        id--;
        chmax(ans,value);
    }
    cout << ans << endl;
}