#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	int p = n * a;
	int ans = min(p, b);
	cout << ans << endl;
	return 0;
}