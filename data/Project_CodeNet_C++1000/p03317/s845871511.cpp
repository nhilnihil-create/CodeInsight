#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

int main() {         
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	int cnt = 0;
	while (n > 0) {
		n -= k;
		if (n <= 0) {
			cnt++;
			break;
		}
		n++;
		cnt++;
	}
	cout << cnt;
}
