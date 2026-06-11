#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n, k; cin >> n >> k;
	const int p = 200001;
	vector<int> num(p);
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		num[a]++;
	}
	sort(num.begin(), num.end(), greater<int>());
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		cnt += num[i];
	}
	cout << n - cnt << endl;
	return 0;
}