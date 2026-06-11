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

	int n; cin >> n;
	
	vector<double> x(n);
	vector<string> u(n);
	double ans = 0;

	rep(i, 0, n) {
		cin >> x[i] >> u[i];
		if (u[i] == "JPY") ans += x[i];
		if (u[i] == "BTC") ans += x[i] * 380000;
 	}
	cout << ans << endl;

	return 0;
}