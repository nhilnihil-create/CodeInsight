#include "bits/stdc++.h"
using namespace std;

//27
typedef long long ll;

ll power(ll a , ll b) {
    ll ans = 1;
	while (b) {
		if (b & 1) {
			ans = ans  * a;
		}
		a = a * a;
		b  /= 2;
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	int cnt = 0;
	while (1) {
		bool d = 1;
		int index = 0;
		for (int i = 0; i < n; ++i) {
			if (v[i]) {
				d = 0;
				index = i;
				break;
			}
		}
		if (d) {
			break;
		}
		for (int i = index; i < n; ++i) {
			if (v[i] == 0) {
				break;
			}
			v[i]--;
		}
		cnt++;
	}
	cout << cnt;     
} 	

