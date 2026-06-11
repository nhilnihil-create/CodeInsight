#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll X, Y;
    cin >> X >> Y;

    ll ans = 0;

    while(X <= Y) {
        ans++;
        X *= 2LL;
    }

    cout << ans << endl;
}