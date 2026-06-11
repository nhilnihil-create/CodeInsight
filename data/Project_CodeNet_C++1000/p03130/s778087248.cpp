#include"bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	vector<int> judge = { 0,0,0,0 };
	rep(i, 3) {
		int A, B;
		cin >> A >> B;
		judge.at(A - 1)++;
		judge.at(B - 1)++;
	}
	cout << (*max_element(judge.begin(), judge.end()) == 2 ? "YES" : "NO") << endl;
	return 0;
}