#include <iostream>
#include<algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	int D, X;
	cin >> D >> X;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A.at(i);
		X += (D - 1) / A.at(i) + 1;

	}
	cout << X << endl;
}