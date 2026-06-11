#include <bits/stdc++.h>
using namespace std;

void printVec(const vector<vector<int>> v) {
	for (int i = 0;i < v.size();i++) {
		for (int j = 0;j < v[i].size();j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}


int main() {
	int n;
	long long takashi=0;
	
	cin >> n;
	vector<int>A(n);
	vector<int>B(n);
	vector<vector<int>>A_B(n,vector<int>(2));

	
	for (int i = 0;i < n;i++) {
		cin >> A[i] >> B[i];
		A_B[i][1] = A[i] + B[i];

		A_B[i][0] = i;
	}

	sort(A_B.begin(), A_B.end(), [](const vector<int>& alpha, const vector<int>& beta) {return alpha[1] < beta[1];});


	int bit = 1;
	for (int i = 0;i < n;i++) {
		if (bit == 1) {
			takashi += A[A_B[n - i-1][0]];
			bit *= (-1);

		}
	
		else {

			takashi -= B[A_B[n - i-1][0]];
			bit *= (-1);

			
		}

	}

	cout << takashi << endl;
	return 0;
}


