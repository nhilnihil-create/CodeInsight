#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		while (v[i] % 2 == 0) {
			cnt++;
			v[i] /= 2;
		}
	}
	cout << cnt;
}
