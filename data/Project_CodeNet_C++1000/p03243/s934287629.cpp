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

	int n;
	cin >> n;

	int ans = 111;
	rep(i, 2, 11) {
		if (n <= ans) {
			cout << ans << endl;
			return 0;
		}
		ans = i * 100;
		ans += i * 10 + i;
	}

	return 0;
}