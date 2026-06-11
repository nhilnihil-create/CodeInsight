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

	vector<int> p(n);
	rep(i, 0, n) cin >> p[i];

	int sum = 0;
	sort(p.begin(), p.end());

	rep(i, 0, n - 1) sum += p[i];
	sum += p[n - 1] / 2;

	cout << sum << endl;

	return 0;
}