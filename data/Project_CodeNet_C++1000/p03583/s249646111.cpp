#include<bits/stdc++.h>
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define printd(x) printf("%.12f\n", ans);
#define print(x) cout << (x) << endl;
#define Yes() cout << "Yes" << endl;
#define No() cout << "No" << endl;
#define YES() cout << "YES" << endl;
#define NO() cout << "NO" << endl;
#define printa(x, n) for(ll i = 0; i < n; i++) {cout << (x[i]) << " ";} cout << endl;
template<class T> bool chmin(T& a, const T& b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int main(void) {
    ll N;
    cin >> N;

    for (ll i = 1; i <= 3500; i++) {
        for (ll j = 1; j <= 3500; j++) {
            ll ue = N * i * j;
            ll sita = 4 * i * j - N * i - N * j;
            if (sita > 0 && ue % sita == 0) {
                cout << i << " " << j << " " << ue / sita << endl;
                return 0;
            }
        }
    }
    
    return 0;
}
