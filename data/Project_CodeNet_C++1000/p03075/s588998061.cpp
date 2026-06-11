#include "bits/stdc++.h"
using namespace std;

int main() {
	vector<int>A(5);
	for (int n = 0;n<5;++n) {
		cin >> A[n];
	}
	int K;
	cin >> K;
	sort(A.begin(), A.end());
	
	if (A[4]-A[0] > K) {
		cout << ":("<<endl;
	}
	else{
		cout << "Yay!"<<endl;
	}
	return 0;
}