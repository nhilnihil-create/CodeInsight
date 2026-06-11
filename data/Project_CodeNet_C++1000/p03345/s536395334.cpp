#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<map>
#include<math.h>
#include<queue>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
const int mod = 1000000007;
const int INF = 1000000000;
const long long LINF = 1e18;
const int MAX = 510000;
int main() {
	long long int a, b, c,k;
	cin >> a >> b >> c>>k;
	if (k % 2 == 1) {
		cout << b - a << endl;
	}
	else {
		cout << a - b << endl;;
	}

	return 0;
}