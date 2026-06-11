#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
const int MOD = 1e9+7;
const int MOOD = 998244353;
#define PI 3.14159265359
typedef long long ll;
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<ll> a(n);
	vector<ll> sum(n+1);
	map<ll, ll> mp;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		sum[i+1] = sum[i] + a[i];
		sum[i+1] %= m;
		mp[sum[i+1]]++;
	}

	ll ans = 0;
	for (auto x : mp){
		if (x.first % m == 0) ans += x.second;
		ans += x.second*(x.second-1)/2;
	}

	cout << ans << endl;
	return 0;
}