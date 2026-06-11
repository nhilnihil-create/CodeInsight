#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>


using namespace std;



int main() {

	int N;
	string* W;
	bool key = true;

	cin >> N;

	W = new string[N];

	for (int i = 0; i < N; i++) {
		cin >> W[i];
	}

	for (int i = 0; i < N - 1; i++) {
		if (W[i][W[i].size() - 1] != W[i + 1][0]) {
			key = false;
			goto answer;
		}
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (W[i] == W[j]) {
				key = false;
				goto answer;
			}
		}
	}


answer:

	if (key) {
		cout << "Yes";
		}
	else {
		cout << "No";
	}

	return 0;

}