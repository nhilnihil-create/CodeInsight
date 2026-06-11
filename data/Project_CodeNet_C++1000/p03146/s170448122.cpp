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
	int s; cin >> s;
	map<ll, ll> m;
	int a[1000005];
	for(int i=1;i<=1000000;i++){
		if(i==1) a[i] = s;
		else if(a[i-1]%2==0){
			a[i] = a[i-1]/2;
		}
		else if(a[i-1]%2==1){
			a[i] = 3*a[i-1]+1;
		}
		// cout << a[i] << endl;
		m[a[i]]++;
		if(m[a[i]]==2){
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}