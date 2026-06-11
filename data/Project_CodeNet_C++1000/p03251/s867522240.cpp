#include "bits/stdc++.h"
using namespace std;

int main() {
	int N,M,X,Y;
	cin >> N >>M>>X>>Y;
	int x = X;
	for (int n = 0;n<N;++n) {
		int num;
		cin >> num;
		x = max(x, num);
	}
	int y = Y;
	for (int m = 0;m<M;++m) {
		int num;
		cin >> num;
		y = min(y, num);
	}
	if (x>=y) {
		cout << "War"<<endl;
	}
	else {
		cout << "No War" << endl;
	}
	return 0;
}