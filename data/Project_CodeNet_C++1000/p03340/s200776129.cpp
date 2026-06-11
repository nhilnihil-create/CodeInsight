#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++) cin >> A[i];
	long long ans = 0;
	int s_xor = 0, s_plus = 0;
	for (int l = 0, r = 0; l < n; l++) {
		while (r < n) {
			int ns_xor = s_xor ^ A[r], ns_plus = s_plus + A[r];
			if (ns_xor == ns_plus) {
				s_xor = ns_xor; s_plus = ns_plus;
				r++;
			} else break;
		}
		ans += r - l;
		s_xor ^= A[l]; s_plus -= A[l];
	}
	cout << ans << endl;
	return 0;
}