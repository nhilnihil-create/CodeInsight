#include <iostream>
using namespace std;

int main() {

	int N,score = 0,result = 0;

	cin >> N;
	int A[2][110];

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < N; j++)
			cin >> A[i][j];
	}

	

	for (int c = 0; c < N; c++) {
		int i = 0, j = 0;
		score = 0;
		for (j = 0; j <= c; j++) {
			score += A[i][j];
		}
		i++;
		for (j = c; j < N; j++) {
			score += A[i][j];
		}
		if (score > result) result = score;
	}

	cout << result;

	return 0;
}

//made by myself