#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef vector<lint> vlint;

#define inf 1e+9
#define endl "\n"
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

#define m0(x) memset(x, 0, sizeof(x))
#define fill(x, y) memset(x, y, sizeof(x))

#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))

template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

template <class T, class S> inline bool chmax(T &a, S b) {
    if(a < b) {a = b;return 1;} return 0;
}
template <class T, class S> inline bool chmin(T &a, S b) {
    if(a > b) {a = b;return 1;} return 0;
}

int main(){
    int n; cin >> n;
    vlint a(n), b(n), c(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];
    sort(all(a));
    sort(all(c));

    lint ans = 0;
    rep(i, n){
        ans += lb(a, b[i]) * (n - ub(c, b[i]));
    }
    cout << ans << endl;

}
