#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
ll boal[200005] = {};
int main() {
	int n, k;
	cin >> n >> k;
	int boalnumber;
	for (int i = 0; i < n; i++) {
		cin >> boalnumber;
		boal[boalnumber]++;
	}
	sort(boal, boal + n);
	reverse(boal, boal + n);
	ll count = 0;
	int index;
	for (int i = 1; i <= 200000; i++) {
		if (boal[i] > 0) {
			count++;
		}
		if (count == k) {
			index = i;
			break;
		}
	}
	if (count < k) {
		cout << "0" << endl;
		return 0;
	}
	ll ans = 0;
	for (int i = index; i <= 200000; i++) {
		ans += boal[i];
	}
	cout << ans << endl;
	return 0;
}

