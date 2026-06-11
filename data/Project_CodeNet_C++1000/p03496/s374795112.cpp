#include <iostream>

using namespace std;

int N;
long long int a[55];

int main(void) {

	cin >> N;

	long long int tmp;

	for (int i = 1; i <= N; i++) {
		cin >> tmp; a[i] = tmp;
	}

	int sig = 0;
	int max_ab = 0;
	int I;
	for (int i = 1; i <= N; i++) {
		if (abs(a[i]) >= max_ab) { max_ab = abs(a[i]); I = i; if (a[i] >= 0) { sig = 1; }
		else { sig = -1; }
		}
	}


	cout << 2 * N-1 << endl;
	if (sig == 1) {
		for (int i = 1; i <= N; i++) {
			cout << I << " " << i << endl;
		}
		for (int i = 1; i <= N-1; i++) {
			cout << i << " " << i + 1 << endl;
		}
	}
	else {
		for (int i = 1; i <= N; i++) {
			cout << I << " " << i << endl;
		}
		for (int i = N; i >= 2; i--) {
			cout << i << " " << i - 1 << endl;
		}

	}

	//system("pause");
	return 0;
}