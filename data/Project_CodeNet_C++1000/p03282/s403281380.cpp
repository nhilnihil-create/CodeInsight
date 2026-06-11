#include<cstdio>
#include<iostream>
using namespace std;

int main(void) {
	string S;
	cin >> S;
	long long K;
	scanf("%lld", &K);
	for (int i = 0; i < K; i++) {
		if (S[i] != '1') {
			cout << S[i] << "\n";
			return 0;
		}
	}
	cout << "1\n";

	return 0;
}
