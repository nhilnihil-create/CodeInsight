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
	int n[3];
	for(int i=0;i<3;i++){
		cin >> n[i];
	}
	sort(n, n+3);
	cout << n[0]*n[1]/2 << endl;
	return 0;
}