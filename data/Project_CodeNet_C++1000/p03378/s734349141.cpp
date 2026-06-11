#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M, X, a;
	cin >> N >> M >> X;
	int l = 0, r = 0;
	for (int i = 0; i < M; i++) {
		cin >> a;
		if (a < X)
			l++;
		else
			r++;
	}
	cout << min(l, r) << endl;
	return 0;
}