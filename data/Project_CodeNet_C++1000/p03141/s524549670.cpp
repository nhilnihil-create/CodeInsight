#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) {rep(i,x.size()) cout << x[i] << " "; cout << endl;}
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
const int MAX = 2e5;

int main() {
    int n; cin >> n;
    vector<P> data(n);
    vector<P> sum;
    rep(i,n) {
        int a, b; cin >> a >> b;
        data[i] = P(a,b);
        sum.push_back(P(a+b,i));
    }
    sort(rall(sum));
    ll ans = 0;
    rep(i,n) {
        if (i&1) ans -= data[sum[i].second].second;
        else ans += data[sum[i].second].first;
    }
    cout << ans << endl;
}