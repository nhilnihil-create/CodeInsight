#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,a,b,c,d,e;
    cin >> n >> a >> b >> c >> d >> e;
    ll x = min(a,min(b,min(c,min(d,e))));
    ll ans = ((n+x-1)/x) + 4;
    cout << ans << endl;
}