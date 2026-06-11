#include<iostream>

using namespace std;

int main() {
	int N, T, A, H[1100], genzaiti,saiteki=1000000000, bangou=0;

	cin >> N;
	cin >> T >> A;
	for (int i = 0; i < N; i++) {
		cin >> H[i];
	}

	for (int i = 0; i < N; i++) {
		genzaiti = abs(A*1000 - (T*1000 - H[i] * 6));
		if (saiteki >genzaiti) {
			saiteki = genzaiti;
			bangou = i + 1;
		}
	}
	cout << bangou << endl;


	return 0;
}