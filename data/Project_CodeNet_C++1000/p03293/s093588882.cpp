#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>


using namespace std;


int main() {

	string S, T;
	bool key = false;

	cin >> S >> T;
	
	for (int i = 0; i < S.size(); i++) {
		if (S == T) {
			key = true;
		}
		S = S.back() + S.substr(0, S.size() - 1);
	}

	if (key) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	return 0;
}
