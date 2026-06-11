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

	vector<int> a(5);
	int mini = 10;

	rep(i, 0, 5) {
		cin >> a[i];
		if (a[i] % 10 != 0) mini = min(mini, a[i] % 10);
	}

	int ans = 0;
	rep(i, 0, 5) {
		int x = a[i] % 10;
		if (x == 0) ans += a[i];
		else if (x != mini) ans += a[i] + (10 - x);
		else {
			ans += a[i];
			mini = 10;
		}
	}

	cout << ans << endl;

	return 0;
}