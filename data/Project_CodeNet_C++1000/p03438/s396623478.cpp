#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair < ll, ll > PLL;
#define rep(i,n) for (int i = 0; i < (n); ++i)
ll MOD = 1e9+7;
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> cnt(2, 0);
    rep(i, n) cin >> a[i];
    rep(i, n) {
        ll b;
        cin >> b;
        if ( a[i] == b ) continue;
        else if ( a[i] > b ) {
            cnt[1] += a[i] - b;
        }
        else if ( ( b - a[i] ) % 2 == 0 ) {
            cnt[0] += ( b - a[i] ) / 2;
        }
        else {
            cnt[0] += ( b - a[i] ) / 2 + 1;
            cnt[1] += 1;
        }
    }
    if ( cnt[0] <  cnt[1] ) cout << "No" << endl;
    else                    cout << "Yes" << endl;
    return 0;
}
