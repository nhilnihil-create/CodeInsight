#include <bits/stdc++.h>
using namespace std;
#define vec(type) vector<type>

int main() {
	int n, a, b, p;
	cin >> n >> a >> b;

	int q1 = 0, q2 = 0, q3 = 0;
	for (int i = 0; i < n; i++) {
		cin >> p;
		if (p <= a) q1++;
		else if (a < p && p <= b) q2++;
		else q3++;
	}

	cout << min({q1, q2, q3}) << endl;
}