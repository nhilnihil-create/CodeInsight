#include <bits/stdc++.h>
using namespace std;

signed main(){
	int n,a[200010];
	cin >> n;
	map<int,int> counts;
	for(int i = 0;i < n;i++){
		cin >> a[i];
		counts[a[i]]++;
	}
	sort(a,a + n,greater<int>());
	int ans = 0;
	for(int i = 0;i < n;i++){
		int v = (1 << (32 - __builtin_clz(a[i]))) - a[i];
		if((a[i] == v && counts[v] >= 2) || (a[i] != v && counts[v] && counts[a[i]])){
			counts[v]--; counts[a[i]]--;
			ans++;
		}
	}
	cout << ans << endl;
}