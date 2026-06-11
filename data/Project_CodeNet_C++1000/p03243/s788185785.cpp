#include<iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	while (1) {
		if (N % 111 == 0) {
			cout << N << endl;
			break;
		}
		else {
			N++;
		}
	}
}