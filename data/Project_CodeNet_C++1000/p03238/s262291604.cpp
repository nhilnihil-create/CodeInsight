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
	if(n==1){
		cout << "Hello World" << endl;
		return 0;
	}
	if(n==2){
		int a, b;cin >> a >> b;
		cout << a+b << endl;
		return 0;
	}
	return 0;
}