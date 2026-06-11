#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	ll N, K;
	cin >> N >> K;

	ll ans = 0;
	if (K == 0){
		ans = N*N;
	} else {
		for (ll b = K+1; b <= N; ++b){
			ll num = N / b;
			ans += (b - K) * num;
			ll rem = N % b;
			if (rem >= K){
				ans += rem - K + 1;
			}
		}		
	}

	cout << ans << "\n";

	return 0;
}
