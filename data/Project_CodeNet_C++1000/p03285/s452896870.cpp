#include<iostream>

using namespace std;

int main() {
	int N;
	bool flag=false;

	cin >> N;

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 15; j++) {
			if (i * 4 + j * 7 == N) {
				flag = true;
			}
		}
	}
	if (flag) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	


	return 0;
}