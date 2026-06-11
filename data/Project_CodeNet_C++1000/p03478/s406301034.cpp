//Author: Suifeng0214
#include <bits/stdc++.h>
#define int long long
using namespace std;
map <char ,int> mp;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a, b;
	cin >> n >> a >> b;
	int ans = 0;
	for (int i = 1; i <= n; i++){
		int tmp = i, nums=0;
		while(tmp>0){
			nums += tmp %10;
			tmp /= 10;
		}
		if (a <= nums && nums <= b){
			ans += i;
		}
		
	} 
	cout << ans << "\n";
} 