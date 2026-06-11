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
const int MAX = 100005;

int main() {
    int n; cin >> n;
    vector<P> red(n), blue(n);
    vector<bool> check(n,false);
    rep(i,n) {
        int x, y; cin >> x >> y;
        red[i] = P(y,x);
    }
    rep(i,n) {
        int x, y; cin >> x >> y;
        blue[i] = P(x,y);
    }
    sort(all(blue));
    sort(all(red));
    int ct = 0;
    for (auto &p: blue) {
        int index = lower_bound(all(red),P(p.second,-inf))-red.begin();
        for (int i = index-1; i >= 0; i--) {
            if (red[i].second >= p.first) continue;
            if (!check[i]) {
                check[i] = true;
                ct++;
                break;
            }
        }
    }
    cout << ct << endl;
}