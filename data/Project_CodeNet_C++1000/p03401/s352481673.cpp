#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
int a[100005];
int main() {
	int n;
	cin >> n;
	ll sum = 0;
	a[0] = 0;
	a[n + 1] = 0;
	for (int i = 1; i <=n; i++) {
		cin >> a[i];
		sum += abs(a[i] - a[i - 1]);
	}
	sum += abs(a[n + 1] - a[n]);
	ll ans;
	for (int i = 1; i <= n; i++) {
		ans = sum + abs(a[i - 1] - a[i + 1])-(abs(a[i+1]-a[i])+abs(a[i]-a[i-1]));
	
		cout << ans<< endl;
	}
	return 0;
}