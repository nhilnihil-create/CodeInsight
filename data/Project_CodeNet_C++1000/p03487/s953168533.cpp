#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int res = 0;
	int id = 0;
	while (id < n)
	{
		int cnt = upper_bound(a, a + n, a[id]) - a - id;
		if(cnt > a[id]) res += cnt - a[id];
		else if(cnt < a[id]) res += cnt;
		id += cnt;
	}
	cout << res << endl;
	return 0;
}
