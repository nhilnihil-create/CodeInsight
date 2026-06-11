#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	int n, a; cin >> n >> a;
	n %= 500;
	string ret;
	if (n <= a) ret = "Yes";
	else ret = "No";
	cout << ret << endl;
	return 0;
}