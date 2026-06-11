#include <iostream>
#include<vector>

using namespace std;

int N, A, B;
vector<int> V;

int C[300005];

int main(void) {

	cin >> N >> A >> B;

	if (A + B >= N + 2 || (long long int) A*B < (long long int) N) {
		cout << -1 << endl;
	}
	else {
		int num = N;
		for (int i = 1; i <= A; i++) { C[i] = 1; num--; }
		for (int i = 1; i <= A; i++) {
			for (int j = 2; j <= B; j++) { if (num > 0) { C[i]++; num--; } }
			if (num <= 0) { break; }
		}

		for (int i = 1; i <= A; i++) {
			C[i] += C[i - 1];
		}

		for (int i = 1; i <= A; i++) {
			for (int j = C[i]; j > C[i - 1]; j--) { V.push_back(j); }
		}

		for (int i = 0; i < N; i++) {
			if (i == 0) { cout << V[i]; }
			else { cout << " " << V[i]; }
		}
		cout << endl;
	}



	//system("pause");
	return 0;
}