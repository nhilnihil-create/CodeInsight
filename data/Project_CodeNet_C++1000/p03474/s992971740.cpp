#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int A, B;
	scanf("%d %d", &A, &B);
	string S;
	cin >> S;
	string ans = "Yes";
	for (int i = 0; i < A; i++) {
		if (S[i] == '-') {
			ans = "No";
		}
	}
	if (S[A] != '-') ans = "No";
	for (int i = A + 1; i < A + B + 1; i++) {
		if (S[i] == '-') {
			ans = "No";
		}
	}
	cout << ans << "\n";
	return 0;
}
