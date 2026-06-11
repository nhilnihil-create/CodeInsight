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

	string S, T;
	cin >> S >> T;

	string str;

	S = S + S;

	bool jdg = false;

	for (int i = 0; i < T.length(); i++) {
		str = S.substr(i, T.length());
		if (str == T) {
			jdg = true;
		}
	}

	if (jdg == true) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}

