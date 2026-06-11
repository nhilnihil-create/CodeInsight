#include "bits/stdc++.h"

using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	int l = 0;
	int r = 100005;
	for (int n = 0; n < M; ++n) {
		int L, R;
		cin >> L >> R;
		l = max(l, L);
		r = min(r, R);
	}
	if (l>r) {
		cout << 0 <<  endl;
	}
	else {
		cout << (1 + r - l) << endl;
	}
}
