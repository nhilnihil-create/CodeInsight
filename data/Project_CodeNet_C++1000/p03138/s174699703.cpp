#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define rrep(i, n) for (int (i) = 1; (i) <= (n); (i++))
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define yn {puts("Yes");}else {puts("No");}
#define printd(x) printf("%.12f\n", ans);
template<class T> bool chmin(T& a, const T& b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void) {
    ll n, k;
    cin >> n >> k;
    ll a[n];
    rep (i, n) cin >> a[i];

    vector<int> keta(45, 0);
    rep (i, n) {
        rep (j, 44) {
            if (a[i] & 1LL << j) keta[j]++;
        }
    }
    
    ll ans = 0;
    for (int i = 44; i >= 0; i--) {
        bool use1 = false;
        if (keta[i] <= n / 2) {
            if ((1LL << i) <= k) {
                k -= (1LL << i);
                use1 = true;
            }
        }
        if (use1) ans += (1LL << i) * (n - keta[i]);
        else ans += (1LL << i) * keta[i];
    }

    cout << ans << endl;
    return 0;
}