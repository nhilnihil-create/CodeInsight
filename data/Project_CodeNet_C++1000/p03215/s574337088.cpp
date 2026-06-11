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
    int n, k; cin >> n >> k;
    vll a(n+1,0);
    REP(i,n+1) cin >> a[i];
    REP(i,n+1) a[i] += a[i-1];
    vll sums;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            sums.push_back(a[j]-a[i-1]);
        }
    }
    ll ans = 0;
    for (int i = 40; i >= 0; i--) {
        int ct = 0;
        vll tmp;
        rep(j,sums.size()) {
            if (sums[j]>>i&1) {
                ct++;
                tmp.push_back(sums[j]);
            }
        }
        if (ct >= k) {
            ans += 1LL<<i;
            swap(sums,tmp);
        } 
    }
    cout << ans << endl;
}