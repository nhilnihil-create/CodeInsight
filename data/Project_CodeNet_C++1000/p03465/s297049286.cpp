#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
signed main(){
	bitset <4000100> b; 
	int n; cin >> n;
	int sum = 0;
	b[0] = 1;
	for (int i=0; i<n; i++){
		int u; cin >> u;
		sum += u;
		b |= (b<<u);
	}
	int ans = (sum+1)>>1;
	while (ans<=sum){
		if (b.test(ans)){
			cout << ans;
			return 0;
		}
		ans++;
	}
	cout << -1;
}

