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
	ll x[105], y[105], h[105];
	for(int i=0;i<n;i++){
		cin >> x[i] >> y[i] >> h[i];
	}
	for(int i=0;i<=100;i++){
		for(int j=0;j<=100;j++){
			ll H = 0;
			bool flag = true;
			for(int k=0;k<n;k++){
				if(h[k]>0){
					H = h[k]+abs(x[k]-i)+abs(y[k]-j);
					break;
				}
			}
			for(int k=0;k<n;k++){
				if(h[k]!=max((H-abs(x[k]-i)-abs(y[k]-j)), 0LL)){
					flag = false;
					break;
				}
			}
			if(flag){
				cout << i << ' ' << j << ' ' << H << endl;
				return 0;
			}
		}
	}
	return 0;
}