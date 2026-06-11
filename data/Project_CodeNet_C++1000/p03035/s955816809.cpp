#include <bits/stdc++.h>
#define	rep(i,n) for (int i =0; i < (n); ++i)
using namespace std;

int main() {
	int A, B, cost;
	cin >> A >> B;

	if (A >= 13) {
		cost = B;
	} else {
		if (A >= 6) {
			cost = B / 2;
		} else {
			cost = 0;
		}
	}
	cout << cost << endl;
	return 0;
}

