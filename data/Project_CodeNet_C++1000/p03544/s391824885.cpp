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
	int k;
	cin >> k;
	vector<long long int> a(k + 10);
	a.at(0) = 2;
	a.at(1) = 1;
	for (int i = 2; i <= k; i++) {
		a.at(i) = a.at(i - 1) + a.at(i - 2);
	}
	cout << a.at(k ) << endl;

	return 0;
}