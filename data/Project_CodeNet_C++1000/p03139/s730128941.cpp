#include <iostream>
using namespace std;

int main() {
	int N, A, B;
	cin >> N >> A >> B;
	int const ans1 = A < B ? A : B;
	int ans2 = 0;
	if (A + B <= N) ans2 = 0;
	else ans2 = A + B - N;
	cout << ans1 << ' ' << ans2 << endl;
}