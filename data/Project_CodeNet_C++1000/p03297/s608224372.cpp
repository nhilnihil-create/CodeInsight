#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

string solve(long long a, long long b, long long c, long long d) {
	if (b - d > 0) return "No";

	long long E = gcd(b, d);
	long long R = (c + 1) / E * E + (a % E); if (R < c + 1) R += E;

	if (min(a, R) < b) return "No";
	return "Yes";
}

int main() {
	long long T, A, B, C, D;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> A >> B >> C >> D;
		cout << solve(A, B, C, D) << endl;
	}
	return 0;
}