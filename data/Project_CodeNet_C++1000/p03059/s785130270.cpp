#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<iomanip>
#include<typeinfo>
#include<complex>
using namespace std;
using ll = long long int;
const int mod = 1e9 + 7;
#define rep(i, a, b) for(ll i = a;i < b; i++)

int main() {

	int a, b, t;
	cin >> a >> b >> t;

	int ans = 0;

	for (int i = a; i <= t; i += a) {
		ans += b;
	}

	cout << ans << endl;

	return 0;
}