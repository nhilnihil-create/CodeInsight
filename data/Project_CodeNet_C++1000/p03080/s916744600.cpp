#include"bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int N;
	string s;
	cin >> N >> s;
	int count = 0;
	rep(i, N) {
		if (s.at(i) == 'R') count++;
	}
	cout << (count > s.size() / 2 ? "Yes" : "No") << endl;
	return 0;
}