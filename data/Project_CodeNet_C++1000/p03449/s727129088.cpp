#include <iostream>

using namespace std;

int main() {
    int N, a, A[2][100];
    cin >> N;
  	for (int j = 0; j < 2; j++){
		for (int i = 0; i < N; i++){
			cin >> a;
          	A[j][i] = a;
        }
    }
    for (int j = 1; j < N; j++){
        A[0][j] += A[0][j-1];
    }
  	A[1][0] += A[0][0];
	for (int i = 1; i < N; i++){
		A[1][i] += max(A[0][i], A[1][i-1]);
    }

    cout << A[1][N-1] << endl;
  return 0;
}