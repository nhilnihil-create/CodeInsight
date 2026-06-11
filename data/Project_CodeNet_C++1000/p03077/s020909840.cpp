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

	ll n;
	vector<ll> a(5);
	cin >> n;
	ll ans = 5, mini = n;

	rep(i, 0, 5) {
		cin >> a[i];
		mini = min(mini, a[i]);
	}

	ans += (n - 1) / mini;
	cout << ans << endl;

	return 0;
}