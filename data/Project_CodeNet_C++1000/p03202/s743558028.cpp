#include <map>
#include <vector>
#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	bool increasing = true;
	for (int i = 1; i < N; ++i) {
		if (A[i - 1] >= A[i]) increasing = false;
	}
	if (increasing) {
		cout << 1 << endl;
	}
	else {
		int L = 1, R = N + 1;
		while (R - L > 1) {
			int M = (L + R) >> 1;
			map<int, int> d;
			for (int j = 0; j < N; ++j) {
				if (d.lower_bound(A[j]) != d.end() && d[A[j]] == 0) d[A[j]] = 1;
				while (!d.empty() && (--d.end())->first > A[j]) {
					d.erase(--d.end());
				}
				if (d[A[j]] < M) {
					++d[A[j]];
				}
				else {
					int ptr = A[j];
					while (true) {
						d[ptr] = 1;
						if (d[ptr - 1] < M) {
							if (d[ptr - 1] == 0) d[ptr - 1] = 1;
							++d[ptr - 1];
							break;
						}
						else --ptr;
					}
				}
			}
			if (d.begin()->first <= 0) {
				L = M;
			}
			else {
				R = M;
			}
		}
		cout << R << endl;
	}
	return 0;
}