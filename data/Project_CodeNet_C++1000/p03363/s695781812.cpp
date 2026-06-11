#include <bits/stdc++.h>
using namespace std;

map<long long, long long> s;

int main() {
    int n; cin >> n;
	long long a[n], sum = 0;
	s[0] = 1;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		s[sum]++;
	}
	long long res = 0;
	for (auto p : s)
	{
		res += p.second * (p.second-1) / 2;
	}
	cout << res << endl;
	return 0;
}

