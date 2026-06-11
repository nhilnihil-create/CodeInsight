#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int A, B, Q;
	cin >> A >> B >> Q;
	vector<long long> S(A), T(B), X(Q);
	for (int i = 0; i < A; i++) cin >> S[i];
	for (int i = 0; i < B; i++) cin >> T[i];
	for (int i = 0; i < Q; i++) cin >> X[i];
	for (long long x : X) {
		auto it = lower_bound(S.begin(), S.end(), x);
		long long y1 = (it == S.end() ? *(it - 1) : *it);
		long long y2 = (it == S.begin() || it == S.end() ? y1 : *(it - 1));
		auto it2 = lower_bound(T.begin(), T.end(), x);
		long long z1 = (it2 == T.end() ? *(it2 - 1) : *it2);
		long long z2 = (it2 == T.begin() || it2 == T.end() ? z1 : *(it2 - 1));

		cout << min({ abs(y1 - x) + abs(y1 - z1), abs(y1 - x) + abs(y1 - z2),
			abs(y2 - x) + abs(y2 - z1), abs(y2 - x) + abs(y2 - z2),
			abs(z1 - x) + abs(z1 - y1), abs(z1 - x) + abs(z1 - y2),
			abs(z2 - x) + abs(z2 - y1), abs(z2 - x) + abs(z2 - y2) }) << endl;
	}
}