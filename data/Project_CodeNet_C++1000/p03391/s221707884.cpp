#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;
int32_t main(){
	cin >> n;
	bool alleq = true;
	int ans = 0;
	int m = INT_MAX;
	for(int i=0; i<n; ++i){
		int a,b;
		cin >> a >> b;
		if(a != b) alleq = false;
		ans += a;
		if(a > b) m = min(m, b);
	}
	ans -= m;
	if(alleq) cout << 0;
	else cout << ans;
}
