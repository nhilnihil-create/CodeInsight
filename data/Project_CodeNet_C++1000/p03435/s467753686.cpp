#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	int c11, c12, c13, c21, c22, c23, c31, c32, c33;
	cin >> c11 >> c12 >> c13 >> c21 >> c22 >> c23 >> c31 >> c32 >>c33;
	int a1, a2, a3;
	a1 = c11 + c22 + c33;
	a2 = c21 + c32 + c13;
	a3 = c31 + c12 + c23;
	string ret = "No";
	if (a1==a2 && a2==a3) ret = "Yes";
	cout << ret << endl;
	return 0;
}