#include<iostream>

using namespace std;


int main() {
	int n;
	while (cin >> n) {
		int answ = 0;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			answ += a - 1;
		}
		cout << answ << endl;
	}
	return 0;
}
