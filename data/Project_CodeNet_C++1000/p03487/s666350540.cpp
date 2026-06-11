#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin>>n;
	int a[n];
	unordered_map<int, int> m;
	for(int i = 0; i < n; i++) {
		cin>>a[i];
		m[a[i]]++;
	}
	int ans = 0;
	for(auto& it : m){
		if(it.first > it.second) ans+=it.second;
		else ans += (it.second - it.first);
	}
	cout << ans << '\n';
}

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
	//cin>>t;
	int cs = 1;
	while(t--){
		//cout << "Case #" << cs << ":\n";
		solve();
		cs++;
	}
	return 0;
}
