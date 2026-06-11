/**
 *    author:  yoseph
 *    created: 18.07.2020 22:31:47      
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v(n,0);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	int ans = accumulate(v.begin(),v.end(),0) - *max_element(v.begin(),v.end())/2;
	cout << ans << "\n";
	return 0;
}
