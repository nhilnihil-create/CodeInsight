#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k;
	cin >> n >> k;
	string ans = "NO";
	if((n / 2) + (n % 2) >= k)
	{
		ans = "YES";
	}
	cout << ans << endl;
	return 0;
}
