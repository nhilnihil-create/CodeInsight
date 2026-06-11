#include "bits/stdc++.h"
using namespace std;

int main() {
	string S;
	cin >> S;
	int w;
	cin >> w;
	string ansS;
	for (int i = 0; i < S.size(); i+=w) {
		ansS += S[i];
	}
	cout << ansS << endl;
	return 0;
}