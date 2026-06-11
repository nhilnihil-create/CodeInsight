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
    int n, h; cin >> n >> h;
    vint a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    sort(rall(b));
    sort(rall(a));
    int ct = 0;
    rep(i,n) {
        if (a[0] <= b[i]) {
            h -= b[i];
            ct++;
            if (h <= 0) {cout << ct << endl; return 0;}
        }
        else break;
    }
    if (h > 0) ct += (h+a[0]-1)/a[0];
    cout << ct << endl;
}