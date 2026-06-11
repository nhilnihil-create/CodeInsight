#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

ll mygcd(ll a, ll b){
    if(b == 0) return a;
    return mygcd(b, a % b);
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<ll> lg(n);
    lg[0] = a[0];
    for(int i = 1; i < n; i++){
        lg[i] = mygcd(a[i], lg[i-1]);
    }

    vector<ll> rg(n);
    rg[n-1] = a[n-1];
    for(int i = n - 2; i >= 0; i--){
        rg[i] = mygcd(a[i], rg[i+1]);
    }

    ll ans = max(rg[1], lg[n-2]);

    for(int i = 1; i <= n-2; i++){
        ans = max(ans, mygcd(lg[i-1], rg[i+1]));
    }

    cout << ans << endl;
}
