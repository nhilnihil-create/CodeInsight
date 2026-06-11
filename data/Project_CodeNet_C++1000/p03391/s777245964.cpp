#include <iostream>
#include <algorithm>
using namespace std;

long long N, A[1 << 18], B[1 << 18], sum = 0, minx = (1LL << 60);

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i] >> B[i]; sum += A[i];
		if (A[i] > B[i]) minx = min(minx, B[i]);
	}
	if (minx == (1LL << 60)) cout << "0" << endl;
	else cout << sum - minx << endl;
	return 0;
}