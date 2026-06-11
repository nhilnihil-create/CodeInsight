#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int l = 0, r = N;
	for (int i = 0; i < M; i++) {
		int L, R;
		cin >> L >> R;
		l = max(l, L);
		r = min(r, R);
	}
	if (l <= r) cout << r - l + 1 << endl;
	else cout << 0 << endl;
	return 0;
}