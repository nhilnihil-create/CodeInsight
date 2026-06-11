#include<bits/stdc++.h>
using namespace std;
int A, B, col[109][109];
int main() {
	cin >> A >> B;
	swap(A, B);
	for (int i = 50; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			col[i][j] = 1;
		}
	}
	A--; B--;
	for (int i = 1; i <= 47; i += 2) {
		for (int j = 1; j <= 97; j += 2) {
			if (A > 0) { col[i][j] = 1; A--; }
		}
	}
	for (int i = 51; i <= 97; i += 2) {
		for (int j = 1; j <= 97; j += 2) {
			if (B > 0) { col[i][j] = 0; B--; }
		}
	}
	cout << 100 << " " << 100 << endl;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (col[i][j] == 0) {
				cout << ".";
			}
			else {
				cout << "#";
			}
		}
		cout << endl;
	}
}