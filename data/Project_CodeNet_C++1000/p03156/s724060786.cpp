#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, A, B;
	cin >> N >> A >> B;
	int x, y, z;
	x = 0;
	y = 0;
	z = 0;
	for (int i = 0; i < N; ++i) {
		int num;
		cin >> num;
		if (num <= A) {
			x++;
		}
		else if (num <= B) {
			y++;
		}
		else {
			z++;
		}
	}
	cout << min(x, min(y, z)) << endl;
	return 0;
}