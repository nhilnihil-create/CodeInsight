# include <iostream>

using namespace std;

int main()
{
	int N, D, X;
	int A[100] = {0};

	cin >> N;
	cin >> D >> X;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int num = X;
	int count[100] = {0};

	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= D; j += A[i]) {
			count[i]++;
		}
	}

	for (int i = 0; i < N; i++) {
		num += count[i];
	}

	cout << num << '\n';
}