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
	int n; cin >> n;
	int h[105];
	int ans = 0;
	for(int i=0;i<n;i++){
		cin >> h[i];
	}
	for(int i=1;i<=100;i++){
		bool flag = false;
		int cnt = 0;
		for(int j=0;j<n;j++){
			if(flag){
				if(h[j]<i){
					flag = false;
				}
			}else{
				if(h[j]>=i){
					cnt++;
					flag = true;
				}
			}
		}
		ans += cnt;
	}
	cout << ans << endl;
	return 0;
}