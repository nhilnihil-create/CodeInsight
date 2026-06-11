#include <bits/stdc++.h>
using namespace std;

int main () {
	int N, N_cp;
	int temp = 0;
	cin >> N;
	
	N_cp = N;
	while (N_cp > 0) {
		temp += N_cp % 10;
		N_cp /= 10;
	}
	if ((N % temp) == 0) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}
