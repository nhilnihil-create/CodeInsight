#include "bits/stdc++.h"

using namespace std;

int main() {
	int N;
	cin >> N;
	int ncopy = N;
	int f = 0; 
	while (0 != ncopy) {
		f += ncopy % 10;
		ncopy /= 10;
	}
	if (0 == N%f) {
		cout << "Yes"<<endl;
	}
	else{
		cout << "No" << endl;
	}
	return 0;
}
