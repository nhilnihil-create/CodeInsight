#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, K;
    cin >> N >> K;

    ll ans = 0;

    if(K % 2 == 0) {
        ll x = N / K;
        if(N % K >= K / 2LL) {
            x++;
        }
        ans += x * x * x;
    }

    ll x = N / K;
    ans += x * x * x;

    cout << ans << endl;
}