#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <cstring>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

ll INF = 1LL << 60;

int main() {
	int N;
	cin >> N;
	vector<int> A(N), B(N), C(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> B[i];
	for (int i = 0; i < N; i++) cin >> C[i];
	sort(A.begin(), A.end());
	sort(C.begin(), C.end());

	ll count = 0;
	for (int i = 0; i < N; i++) {
		count += (lower_bound(A.begin(), A.end(), B[i]) - A.begin())
			* (C.end() - upper_bound(C.begin(), C.end(), B[i]));
	}
	cout << count << endl;
	return 0;
}