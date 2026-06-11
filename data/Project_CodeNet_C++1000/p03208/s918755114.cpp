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

	int n, k;
	cin >> n >> k;

	vector<int> h(n), diff(n - k + 1);
	rep(i, 0, n) cin >> h[i];

	sort(h.begin(), h.end());
	int ans = 0;

	rep(i, 0, n - k + 1) {
		diff[i] = h[i + k - 1] - h[i];
		//cout << diff[i] << endl;
	}

	sort(diff.begin(), diff.end());
	
	cout << diff[0] << endl;

	return 0;
}