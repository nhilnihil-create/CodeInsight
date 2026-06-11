#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	string s;
	cin >> n >> s;
	vector<int> l(n + 1), r(n + 1);
	for(int i = 0; i < n; i++){
		if(s[i] == '#') l[i + 1]++;
		if(s[n - i - 1] == '.') r[n - i - 1]++;
		l[i + 1] += l[i];
		r[n - i - 1] += r[n - i];
	}
	int ans = 1001001001;
	for(int i = 0; i < n; i++){
		ans = min(ans, l[i] + r[i + 1]);
	}
	cout << ans << endl;
	return 0;
}