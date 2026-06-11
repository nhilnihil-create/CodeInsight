#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	string s;
	cin >> n >> s;
	vector<int> a(n + 1), b(n + 1);
	for(int i = 0; i < n; i++){
		if(s[i] == '#') a[i + 1]++;
		if(s[n - i - 1] == '.') b[n - i - 1]++;
		a[i + 1] += a[i];
		b[n - i - 1] += b[n - i];
	}
	int ans = 100100100;
	for(int i = 0; i < n; i++){
		ans = min(ans, a[i] + b[i + 1]);
	}
	cout << ans << endl;
	return 0;
}