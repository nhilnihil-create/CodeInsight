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
const long double PI = (acos(-1));

int main() {

	int a, b, c;
	cin >> a >> b >> c;

	int ans = a * 10 + b + c;
	if (ans < a + b * 10 + c) {
		ans = a + b * 10 + c;
	}
	if (ans < a + b + c * 10) {
		ans = a + b + c * 10;
	}

	cout << ans << endl;

	return 0;
}