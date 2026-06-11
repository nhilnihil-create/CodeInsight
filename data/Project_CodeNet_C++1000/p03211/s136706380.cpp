#include <bits/stdc++.h>
using namespace std;
int main() {
	string S;
	cin >> S;
	vector<string>A(S.size() - 2);
	vector<int>B(S.size() - 2);
	vector<int>C(S.size() - 2);

	for (int i = 0; i < S.size() - 2; i++) {
		A[i] = S.substr(i, 3);
	}
	for (int i = 0; i < S.size() - 2; i++) {
		B[i] = stoi(A[i]);
	}
	for (int i = 0; i < S.size() - 2; i++) {
		C[i] = abs(753 - B[i]);
	}
	sort(C.begin(), C.end());
	cout << C[0] << endl;
}
