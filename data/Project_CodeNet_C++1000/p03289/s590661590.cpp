#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>


using namespace std;


int solve(string S);


int main() {

	string S;

	cin >> S;

	if (solve(S)) {
		cout << "AC";
	}
	else {
		cout << "WA";
	}
	
	return 0;

}

int solve(string S) {
	int count = 0, key=0, c;
	if (S[0] != 'A') {
		return false;
	}

	for (int i = 2; i < S.size() - 1; i++) {
		if (S[i] == 'C') {
			count++;
			c = i;
		}
	}
	if (count != 1) {
		return false;
	}

	for (int i = 0; i < S.size(); i++) {
		if (i != 0 && i != c) {
			if (!islower(S[i])) {
				return false;
			}
		}
	}

	return true;
}