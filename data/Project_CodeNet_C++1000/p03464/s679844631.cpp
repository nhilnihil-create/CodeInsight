#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll l = 2;
    ll r = 2;
    for ( int i = n - 1; i >= 0; --i ) {
        ll tmp_l = ( l + a[i] - 1 ) / a[i];
        ll tmp_r = r / a[i];
        if ( tmp_l > tmp_r ) {
            puts("-1");
            return 0;
        }
        l = tmp_l * a[i];
        r = ( tmp_r + 1 ) * a[i] - 1;
    }
    cout << l << " " <<  r << endl;
    return 0;
}