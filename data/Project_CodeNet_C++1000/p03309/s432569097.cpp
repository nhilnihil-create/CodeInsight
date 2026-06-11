/**
*    created: 28.06.2020 01:44:53
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pcnt(bit) __builtin_popcountll(bit)
using namespace std;
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b; return 1;} return 0;}
const int mod = 1000000007;
const long double pi = acos(-1.0);
const int inf = 1LL << 60;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n) a[i] -= i+1;
    sort(all(a));
    int ans = 0;
    if (n % 2 == 1) {
        int q = a[(n+1)/2-1];
        rep(i,n) ans += abs(q-a[i]);
        cout << ans << endl;
    }
    else {
        int l = a[n/2-1];
        int r = a[n/2];
        int p;
        int sum = inf;
        for (int i = l; i <= r; i++) {
            if (abs(i-l)+abs(i-r) < sum) {
                sum = abs(i-l)+abs(i-r);
                p = i;
            }
        }
        rep(i,n) ans += abs(p-a[i]);
        cout << ans << endl;
    }
    return 0;
}