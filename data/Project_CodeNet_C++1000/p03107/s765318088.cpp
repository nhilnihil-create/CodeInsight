#include "bits/stdc++.h"
using namespace std;

int main() {
	string S;
	cin >> S;
	int x = 0;
	int y = 0;
	for (int n = 0;n<S.size();++n) {
		if ('0' == S[n]) {
			++x;
		}
		else {
			++y;
		}
	}
	cout << 2*min(x,y) <<  endl;
}
