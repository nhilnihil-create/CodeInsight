#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll x[200005];
ll check[200005];
int main() {
	ll n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		check[i] = x[i];
	}
	sort(check, check + n);
	double index = (double)(check[n / 2] + check[n / 2 - 1]) / 2;
	for (int i = 0; i < n; i++) {
		if (x[i] >= index) {
			cout << check[n / 2 - 1] << endl;
		}
		else {
			cout << check[n / 2] << endl;
		}
	}
	return 0;
}
