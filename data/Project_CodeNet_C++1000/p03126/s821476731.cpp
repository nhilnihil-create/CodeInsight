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

	int n, m;
	cin >> n >> m;

	int k, a, ans = 0;
	map<int, int> cnt;

	rep(i, 0, n) {
		cin >> k;
		rep(i, 0, k) {
			cin >> a;
			cnt[a]++;
			if (cnt[a] == n) ans++;
		}
	}

	cout << ans << endl;

	return 0;
}