#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	int P = 0;
	int W = 0;
	int G = 0;
	int Y = 0;
	int cnt = 4;
	char S;
	cin >> N;
	
	for (int i=0; i < N; i++) {
		cin >> S;
		if (S == 'P') P++;
		if (S == 'W') W++;
		if (S == 'G') G++;
		if (S == 'Y') Y++;
	}
	
	if (P == 0) cnt--;
	if (W == 0) cnt--;
	if (G == 0) cnt--;
	if (Y == 0) cnt--;
	
	if (cnt == 3) {
		cout << "Three" << endl;
	}
	else {
		cout << "Four" << endl;
	}
}
