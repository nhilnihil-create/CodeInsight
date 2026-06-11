#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<char, char>P;
long long GCD(long long A, long long B) {
	if (B == 0) return A;
	else return GCD(B, A % B);
}
int main() {
	long long N, M; cin >> N >> M;
	long long ans = (N * M) / GCD(N, M);
	map<long long, char>A;
	string S; cin >> S;
	for (long long i = 0; i < N; i++) {
		A[(i * (ans / N)) + 1] = S.at(i);
	}
	string T; cin >> T;
	for (long long i = 0; i < M; i++) {
		if (A[i * (ans / M) + 1] >= 97 && A[i * (ans / M) + 1] <= 123 && A[i * (ans / M) + 1] != T.at(i)) {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << ans << endl;
}