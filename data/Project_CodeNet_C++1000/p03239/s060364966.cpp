#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using G = vector<vector<int>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll MOD = 1000000007;

ll GCD(ll x, ll y){
	return y ? GCD(y, x%y) : x;	
}

int main() {
	int N, T; cin >> N >> T;
	int c[105], t[105];
	int ans = 0;
	for(int i=0;i<N;i++){
		cin >> c[i] >> t[i];
		ans = max(c[i], ans);
	}
	ans++;
	int cost = ans;
	for(int i=0;i<N;i++){
		if(t[i]<=T){
			ans = min(ans, c[i]);
		}
	}
	if(ans!=cost){
		cout << ans << endl;
		return 0;
	}else{
		cout << "TLE" << endl;
		return 0;
	}
	return 0;
}