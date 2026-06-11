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

	int a, b, k;
	cin >> a >> b >> k;

	int x = min(a, b) + 1;
	while (k > 0) {
		x--;
		if (a % x == 0 && b % x == 0) k--;
	}
	cout << x << endl;

	return 0;
}