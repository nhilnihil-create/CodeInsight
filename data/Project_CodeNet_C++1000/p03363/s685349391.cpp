#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	long long a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(i > 0) a[i] += a[i-1];
	}
	sort(a, a + n);
	long long res = 0;
	int id = 0;
	while (id < n)
	{
		long long cnt = upper_bound(a, a + n, a[id]) - a - id;
		if(a[id] == 0) res += cnt;
		res += cnt * (cnt - 1) / 2;
		id += cnt;
	}
	cout << res << endl;
	return 0;
}

