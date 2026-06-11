#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
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
    vint a(n);
    rep(i,n) cin >> a[i];
    ll ans = 0;
    int l = 0, r = 0;
    ll sum = 0;
    while (l < n) {
        while (r < n && (sum^a[r]) == (sum+a[r])) {
            sum ^= a[r++];
            ans++;
        }
        sum ^= a[l++];
        ans += r-l;
    }
    cout << ans << endl;
}