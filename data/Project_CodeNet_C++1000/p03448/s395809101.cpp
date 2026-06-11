#include <bits/stdc++.h>
# define M_PI           3.14159265358979323846  /* pi */
using namespace std;

int main() {
	int A, B, C;
	int X;
	cin >> A >> B >> C >> X;
	int count = 0;

	vector<int>a(A + 1);
	vector<int>b(B + 1);
	vector<int>c(C + 1);

	for (int i = 0; i < A + 1; i++) {
		a.at(i) = (i) * 500;
	}
	for (int i = 0; i < B + 1; i++) {
		b.at(i) = (i) * 100;
	}
	for (int i = 0; i < C + 1; i++) {
		c.at(i) = (i) * 50;
	}

	for (int i = 0; i < A + 1; i++) {
		for (int j = 0; j < B + 1; j++) {
			for (int k = 0; k < C + 1; k++) {
				if (a.at(i) + b.at(j) + c.at(k) == X)count++;
			}
		}
	}
	cout << count << endl;
}