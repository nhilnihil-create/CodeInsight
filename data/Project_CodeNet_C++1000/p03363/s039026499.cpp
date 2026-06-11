#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<long long> a(n + 1);
	map<long long, long long> m;
	m[0]++;
	long long ans = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i + 1];
		a[i + 1] += a[i];
		ans += m[a[i + 1]]++;
	}
	cout << ans << endl;
	return 0;
}