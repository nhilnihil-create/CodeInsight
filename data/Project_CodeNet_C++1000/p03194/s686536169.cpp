#include <bits/stdc++.h>
using namespace std;

int main() {
	long long N, P;
	cin >> N >>  P;
	long long tmp = 0, max = 0, ans = 1;
	max = exp(log(P) / N)+1;
	for (long long i = max; i > 1; i--) {
		tmp = pow(i, N);
		if (P%tmp == 0) {
			ans = i;
			break;
		}
	}
	cout << ans << endl;
}
