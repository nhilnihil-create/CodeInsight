#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){

    ll a, b, c, k;
    cin >> a >> b >> c >> k;

    ll ans = a - b;
    if (abs(ans) > INF) cout << "Unfair" << endl;
    else if (k%2 == 0) cout << ans << endl;
    else cout << -1*ans << endl;
    return 0;
}