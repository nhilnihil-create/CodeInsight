#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	
	int n, k;
	cin >> n >> k;
	ll ans = 0;
	if(k == 0){
		ans = (ll) n * n;
	}else{
		for(int i = 1; i <= n; i++){
			if(i > k){
				ans += (ll) (n / i) * (i - k);
				ans += max(0, (n % i) - k + 1);
			}
			// cout << i << " " << ans << endl;
		}
	}
	cout << ans << endl;
	return 0;
}