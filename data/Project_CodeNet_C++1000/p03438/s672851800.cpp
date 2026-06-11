#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll>PLL;
#define rep(i,n) for (int i = 0; i < (n); ++i)
ll MOD = 1e4+7;
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    ll k = 0;
    rep(i, n) k += b[i] - a[i];
    ll anum = 0;
    rep(i, n)  if ( b[i] > a[i] ) anum += ( b[i] - a[i] + 1 ) / 2;
    if ( anum > k ) cout << "No" << endl;
    else            cout << "Yes" << endl;
    return 0;
}

