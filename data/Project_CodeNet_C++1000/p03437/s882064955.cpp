#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include<stack>
#include <unordered_map>

int gcd(int a, int b) {
	if (b == 0)return a;
	return gcd(b, a % b);
}

using namespace std;

int main() {
	int X, Y;
	cin >> X >> Y;
	if (X % Y == 0) {
		cout << -1;
		return 0;
	}
	int a = gcd(X, Y);
	Y /= a;
	long long ans = X;
	cout << ans * (Y - 1);

	return 0;
}

