#include "bits/stdc++.h"
using namespace std;

int main(){
	int N;
	cin >> N;

	vector<int> L(N,1);

	int sum = 0;

	for(int i = 0;i < N;i++){
		int n;
		cin >> n;

		L.at(i) = n;
		sum += L.at(i);
	}

	int j = 0;

	for (int i = 0;i < N;i++) {
		if (L.at(i) >= (sum - L.at(i))) {
			j += 1;
		}
	}

	if (j > 0) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}
	

}