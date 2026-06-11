#include <bits/stdc++.h>
# define M_PI           3.14159265358979323846  /* pi */
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int>A(N);
	for (int i = 0; i < N; i++) {
		cin >> A.at(i);
	}
	sort(A.begin(), A.end());

	int count = 0;
	int k = 0;
	for (int i = 0; i < N; i++) {
		if (k < A.at(i)) count++;
		k = A.at(i);
	}
	cout << count << endl;

}