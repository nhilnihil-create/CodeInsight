#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, Q, ansL, ansR, L, R;
	string S;
	static pair<char, char> A[200000];
	cin >> N >> Q >> S;
	for (int i = 0; i < Q; i++) {
		cin >> A[i].first >> A[i].second;
	}
	L = 0, R = N;
	while (R - L > 0) {
		int mid = (L + R) / 2, G = mid;
		bool check = true;
		for (int i = 0; i < Q; i++) {
			if (S[G] == A[i].first) {
				if (A[i].second == 'L') G--;
				else G++;
			}
			if (G < 0) {
				check = false;
				break;
			}
			if (G >= N) {
				break;
			}
		}
		if (check) R = mid;
		else L = mid + 1;
	}
	ansL = R;
	L = 0, R = N;
	while (R - L > 0) {
		int mid = (L + R) / 2, G = mid;
		bool check = true;
		for (int i = 0; i < Q; i++) {
			if (S[G] == A[i].first) {
				if (A[i].second == 'L') G--;
				else G++;
			}
			if (G >= N) {
				check = false;
				break;
			}
			if (G < 0) {
				break;
			}
		}
		if (check) L = mid + 1;
		else R = mid;
	}
	ansR = L;
	cout << ansR - ansL;
}