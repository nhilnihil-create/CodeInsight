#include "bits/stdc++.h"
using namespace std;

int main() {
	int N ;
	cin >> N;
	map<int,int>A;
	map<int,int>B;
	for (int n = 0;n<N;++n) {
		int num;
		cin >> num;
		if (0 == n%2) {
			A[num]++;
		}
		else {
			B[num]++;
		}
	}
	int A0 = 0;
	int a0 = 0;
	int A1 = 0;	
	int a1 = 0;
	for (auto itr = A.begin(); itr != A.end(); ++itr) {
		if (A0 < itr->second) {
			A0 = itr->second;
			a0 = itr->first;
		}
	}	
	for (auto itr = A.begin(); itr != A.end(); ++itr) {
		if (A1 < itr->second && itr->first != a0) {
			A1 = itr->second;
			a1 = itr->first;
		}
	}
	int B0 = 0;
	int b0 = 0;
	int B1 = 0;
	int b1 = 0;
	for (auto itr = B.begin(); itr != B.end(); ++itr) {
		if (B0 < itr->second) {
			B0 = itr->second;
			b0 = itr->first;
		}
	}
	for (auto itr = B.begin(); itr != B.end(); ++itr) {
		if (B1 < itr->second && itr->first != b0) {
			B1 = itr->second;
			b1 = itr->first;
		}
	}
	int ans = 0;
	if (a0 == b0) {
		ans = min(N - A0 - B1, N - A1 - B0);
	}
	else {
		ans = N - A0 - B0;
	}
	cout << ans <<endl;
	return 0;
}