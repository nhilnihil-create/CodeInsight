#include <bits/stdc++.h>
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) x.begin(),x.end()
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    rep (i, n) cin >> a[i];
    vector<int> l(n+1, 0);
    vector<int> r(n+1, 0);
    rep (i, n) l[i+1] = gcd(l[i], a[i]);
    for (int i=n-1; i>=0; --i) r[i] = gcd(r[i+1], a[i]);
    int ans=0;
    rep (i, n) {
        int le = l[i];
        int ri = r[i+1];
        chmax(ans, gcd(le, ri));
    }
    cout << ans << endl;
    return 0;
}