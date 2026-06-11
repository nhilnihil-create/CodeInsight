#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<bitset>
using namespace std;

int main() {

	string S;
	cin >> S;

	for (int i = 0; i < S.length(); i++) {
		if ('1' == S[i]) {
			S[i] = '9';
		}
		else {
			S[i] = '1';
		}
	}

	cout << stoi(S) << endl;

	return 0;
}
