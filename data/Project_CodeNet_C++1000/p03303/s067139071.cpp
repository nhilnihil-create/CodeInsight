#include <bits/stdc++.h>
using namespace std;

int main() {
	string S, K;
	int w;;
	cin >> S >> w;
	for (int i = 0; i < S.size(); i += w) {
		K += S.at(i);
	}
	cout << K << endl;
}