#include <iostream>

typedef long long ll;

using namespace std;

int main() {
	int n;
	int x;
	cin >> n >> x;
	ll arr[200001]{};
	for(int i = 0; i < n; i++) {
		cin >> arr[n-i];
	}
	for(int i = 1; i <= n; i++) {
		arr[i] += arr[i-1];
	}

	ll ans = 1LL<<60;
	for(int i = 1; i <= n; i++) {
		ll sum = 0;
		ll gcount = 1;
		for(int j = 0; j < n; j+=i) {
			ll l = arr[min(j+i,n)]-arr[j];
			if(gcount==1) {
				sum += l*5LL;
			}else {
				sum += (2LL*gcount+1LL)*l;
			}
			gcount++;
		}
		sum += ((ll)i)*x;
		if(sum>=0LL) ans = min(ans,sum);
	}

	ans += ((ll)n)*x;

	cout << ans << endl;
}
