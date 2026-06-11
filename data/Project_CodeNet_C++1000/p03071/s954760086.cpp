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

	int a, b;
	cin >> a >> b;

	int ans = 0;

	rep(i, 0, 2) {
		if (a > b) {
			ans += a;
			a--;
		}
		else {
			ans += b;
			b--;
		}
	}

	cout << ans << endl;

	return 0;
}