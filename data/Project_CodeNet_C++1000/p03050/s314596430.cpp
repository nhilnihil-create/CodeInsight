#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long N;
	cin >> N;
	long long ans = 0;
	for (long long i = 1; i <= (long long)sqrt(N) + 1; i++) if (N % i == 0 && (N - i) / i > i) ans += (N - i) / i;
	cout << ans << endl;
}
