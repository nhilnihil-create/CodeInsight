#include<iostream>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	int num = 1;
	for (int i = 0; i < K-1; i++) {
		num += 2;
	}

	if (num <= N) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	
	
}
