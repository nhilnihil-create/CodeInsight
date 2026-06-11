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
    int n; cin >> n;
    vint c(n-1), s(n-1), f(n-1);
    rep(i,n-1) cin >> c[i] >> s[i] >> f[i];
    rep(i,n) {
        int t = 0;
        for (int j = i; j < n-1; j++) {
            t = max(t,s[j]);
            if ((t-s[j])%f[j] != 0) {
                t += f[j]-(t-s[j])%f[j];
            }
            t += c[j];
        }
        cout << t << endl;
    }
}