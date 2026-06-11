#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> D(N);
	for (int i = 0; i < N; i++) cin >> D[i];
	sort(D.begin(), D.end());
	int MIN = 12;
	int bp = 0, bm = 0;
	for (int i = 0; i < N; i++) {
		if (min({ D[i] - bp, 24 - D[i] + bp, D[i] - bm, 24 - D[i] + bm })
	> min({ D[i] + bm, 24 - D[i] - bm,D[i] + bp, 24 - D[i] - bp })) {
			MIN = min({ MIN, D[i] - bp, 24 - D[i] + bp, D[i] - bm, 24 - D[i] + bm });
			bp = D[i];
		}
		else {
			MIN = min({ MIN, D[i] + bm, 24 - D[i] - bm,D[i] + bp, 24 - D[i] - bp });
			bm = -D[i];
		}
	}
	cout << MIN << endl;
}