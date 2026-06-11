#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>


using namespace std;


int main() {

	string key = "keyence", S;
	bool ans = false;

	cin >> S;

	int i = 0, j = 0;

	for (i = 0; i <= S.size(); i++) {
		for (j = i; j <= S.size(); j++) {
			if (S.substr(0, i) + S.substr(j, S.size()) == key) {
				ans = true;
				break;
			}
		}
	}

	if (ans) {
		cout << "YES";
	}
	else{
		cout << "NO";
	}

	return 0;
}
