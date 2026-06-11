#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <map>
const int MOD = 1e9+7;
typedef long long ll;
using namespace std;

int main(){
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<ll> coun(50);
	for (int i = 0; i < 50; i++){
		for (int j = 0; j < n; j++){
			if (a[j] & (1LL<<i)) coun[i]++;
		}
	}

	ll ans = 0;
	bool used = false;
	for (int i = 49; i >= 0; i--){
		if ((1LL<<i) & k || used){
			if (coun[i] < n - coun[i]){
				ans += (1LL<<i)*(n-coun[i]);
			}else{
				ans += (1LL<<i)*coun[i];
				used = true;
			}
		}
		else ans += (1LL<<i)*(coun[i]);
	}
	cout << ans << endl;
	return 0;
}