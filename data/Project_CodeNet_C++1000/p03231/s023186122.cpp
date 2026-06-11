#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	return (b == 0 ? a : gcd(b, a % b));
}
int main() {
	int N, M;
	string A, B;
	cin >> N >> M >> A >> B;
	int GCD = gcd(N, M);
	long long LCM = (long long)N / GCD * M;
	bool ans = true;
	for (int i = 0; i < GCD; i++) if (A[i * N / GCD] != B[i * M / GCD]) ans = false;
	cout << (ans ? LCM : -1) << endl;
}
