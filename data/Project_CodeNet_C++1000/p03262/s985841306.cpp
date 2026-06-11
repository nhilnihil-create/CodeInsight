#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long

int main(void)
{
    ll n, x, ans;
    cin >> n >> x;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ans = abs(x-a[0]);
    rep(i,n){
        ans = __gcd(ans, abs(x-a[i]));
    }
    cout << ans << endl;
    return 0;
}