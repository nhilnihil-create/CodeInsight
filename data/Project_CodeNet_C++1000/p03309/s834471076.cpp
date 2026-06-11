#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(), x.end()
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const ll inf = 1e9;
const int MAX_N = 500;

int main() {
    int n; cin >> n;
    vector<double> a(n);
    rep(i,n) {
        double x; cin >> x;
        x -= (i+1);
        a[i] = x;
    }
    sort(all(a));
    int median = a[n/2];
    ll ans = 0;
    rep(i,n) ans += abs(a[i]-median);
    cout << ans << endl; 
}