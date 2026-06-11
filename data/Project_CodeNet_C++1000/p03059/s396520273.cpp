#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
	int a,b,t;
	cin >> a >> b >> t;
	cout << ((t/a)*b) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while(t--){ 
		solve();
	}
	return 0;
}