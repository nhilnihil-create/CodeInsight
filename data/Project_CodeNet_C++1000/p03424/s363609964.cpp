#include <iostream> 
using namespace std;
int main() {
	int N, Ycount;
	cin >> N;

	Ycount = 0;

	for (int i = 0; i < N; i++) {
		char S;
		cin >> S;

		if (S == 'Y') {
			Ycount++;
		}
	}

	if (Ycount > 0) {
		cout << "Four" << endl;
	}

	else {
		cout << "Three" << endl;
	}
}