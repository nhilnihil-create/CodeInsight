#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
#define MOD 1000000007
#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef long double ld;

int main(){
    ll N, H;
    cin >> N >> H;
    vector<ll> a(N,0),b(N,0);
    rep(i,N) cin >> a[i] >> b[i];

    sort(all(a),greater<ll>());
    sort(all(b),greater<ll>());
    
    ll ans = 0;
    rep(i, N){
        if(H <= 0 || b[i] <= a[0]){
            ans = i - 1;
            break;
        } 
        H -= b[i];
        ans = i;
    }
    
    if(H > 0){
        ans += H / a[0];
        H -= a[0] * (H / a[0]);
    }

    if(H > 0) ans++;

    cout << ans + 1 << endl;
}
