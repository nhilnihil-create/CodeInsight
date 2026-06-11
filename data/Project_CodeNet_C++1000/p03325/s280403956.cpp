#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
const int MOD = 1e9+7;
#define PI 3.14159265359
typedef long long ll;
using namespace std;

ll mod2(ll x){
	ll coun = 0;
	while (x % 2 == 0){
		x /= 2;
		coun++;
	}
	return coun;
}


int main(){
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	ll ans = 0;
	for (int i = 0; i < n; i++){
		ans += mod2(a[i]);
	}
	cout << ans << endl;
	return 0;
}