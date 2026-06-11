#include<iostream>
#include<algorithm>

using namespace std;

void printans(int x, int y) {
	for (int i = 1; i <= x; i++)cout << 3 * i << " ";
	for (int i = 1; i <= y; i++) {
		if(i % 2 == 1)cout << ((i - 1) / 2) * 6 + 2;
		else cout << ((i - 1) / 2) * 6 + 4;
		if (i != y)cout << " ";
	}
	cout << endl;
}

int main() {
	int N;
	cin >> N;
	if (N == 3)cout << "2 5 63" << endl;
	else if (N == 4)cout << "2 5 20 63" << endl;
	else {
		if (N % 2 == 1) {
			int a = min(9999, (N / 4 - 1) * 4 + 3);
			int b = N - a;
			printans(a, b);
		}
		else {
			int a = min(10000, ((N - 1) / 4) * 4);
			int b = N - a;
			printans(a, b);
		}
	}
	return 0;
}