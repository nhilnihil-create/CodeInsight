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

	int H, W;
	bool ans = true, key = false;

	cin >> H >> W;
	
	vector<vector <char> > S(H + 2, vector<char>(W + 2));
	int dx[4] = { -1, 0 ,1 ,0 };
	int dy[4] = { 0,1, 0, -1 };


	for (int i = 1; i <= H ; i++) {
		for (int j = 1; j <= W; j++) {
			cin >> S[i][j];
		}
	}

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (S[i][j] == '#') {
				key = false;
				for (int k = 0; k < 4; k++) {
					if (S[i + dx[k]][j + dy[k]] == '#') {
						key = true;
					}
				}
				if (!key) {
					ans = false;
					goto Ans;
				}
			}
		}
	}

	Ans:

	if (ans) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	return 0;
}
