#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	vector<int> A(N), B(N), C(N);
	for (int i = 0; i < N; i++) cin >> A.at(i);
	for (int i = 0; i < N; i++) cin >> B.at(i);
	for (int i = 0; i < N; i++) cin >> C.at(i);

	sort(A.begin(), A.end());
	sort(C.begin(), C.end());

	int64_t ans = 0;
	for (int i = 0; i < N; i++) {
		int64_t n, m;
		n = lower_bound(A.begin(), A.end(), B.at(i)) - A.begin();
		m = C.end() - upper_bound(C.begin(), C.end(), B.at(i));
		ans += n * m;
	}

	cout << ans << endl;
}