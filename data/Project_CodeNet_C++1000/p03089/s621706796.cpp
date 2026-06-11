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
	vector<int> v;
	for(int i=0;i<n;i++){
		int b; cin >> b;
		b--;
		v.push_back(b);
	}
	vector<int> ans;
	for(int i=0;i<n;i++){
		for(int j=n-i-1;j>=0;j--){
			if(j<v[j]){
				cout << -1 << endl;
				return 0;
			}
			else if(j==v[j]){
				ans.push_back(v[j]);
				v.erase(v.begin()+j);
				break;
			}
		}
	}
	for(int i=n-1;i>=0;i--){
		cout << ans[i]+1 << endl;
	}
	return 0;
}