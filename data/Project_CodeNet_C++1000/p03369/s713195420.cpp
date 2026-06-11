#include<iostream>
#include<vector>
#include<utility>
#include<map>
#include<algorithm>

using namespace std;
using ll = long long;

int main() {
	string S;
	cin >> S;

	int A = 0;

	for (int i = 0; i < 3; i++) {
		if (S[i] == 'o') {
			A++;
		}
	}

	cout << 700 + 100 * A << endl;
}