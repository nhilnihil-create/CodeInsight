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

	int n, ans;
	double t, a, mini = 100000;
	cin >> n >> t >> a;

	vector<double> h(n);
	rep(i, 0, n) {
		cin >> h[i];
		h[i] = t - h[i] * 0.006;
		h[i] = abs(a - h[i]);
		if (h[i] < mini) {
			mini = h[i];
			ans = i + 1;
		}
	}

	cout << ans << endl;

	return 0;
}