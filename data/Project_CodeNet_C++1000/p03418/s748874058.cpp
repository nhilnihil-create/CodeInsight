#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, K;
    cin >> N >> K;

    ll ans = 0;

    if(K == 0) {
        cout << N * N << endl;
        return 0;
    }

    for(ll i = K + 1; i <= N; i++) {
        ans += (i - K) * (N / i);
        ans += max(0LL, N % i - K + 1);
    }

    cout << ans << endl;
}