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
const int inf = 1e9+10;
const ll inf_l = 1e18;
const int MAX = 1e5;

int main() {
    int m, k; cin >> m >> k;
    if (m == 1 && k == 0) {
        cout << 0 << " " << 0 << " " << 1 << " " << 1 << endl;
        return 0;
    }
    int sum = 0;
    rep(i,1<<m) {
        if (i == k) continue;
        sum ^= i;
    }
    if (sum != k) cout << -1 << endl;
    else {
        deque<int> q;
        q.push_back(k);
        rep(i,1<<m) {
            if (i == k) continue;
            q.push_front(i);
            q.push_back(i);
        }
        q.push_back(k);
        while (!q.empty()) {
            int v = q.front(); q.pop_front();
            cout << v << " ";
        }
    }
}