//ProblemD

#ifdef _MYPC
#include "mypc.h"
#endif // _MYPC

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <memory>
#include <cstdio>
#include <cstring>

using namespace std;

//ProblemD
#define MAXL 300

class Solve {
private:
	string S;
	int K;
	int n;

	int dp[MAXL+1][MAXL+1][MAXL+1]{};

	void solve() {
		cin >> S >> K;
		n = S.length();

		for (int k = 0; k <= K; k++) {
			for (int i = 0; i < n; i++) {
				dp[k][i][i + 0] = 1;
			}

			for (int l = 1; l < n; l++) {
				for (int i = 0; i < n - l; i++) {
					int j = i + l;

					if (S[i] == S[j]) {
						dp[k][i][j] = 2 + dp[k][i + 1][j - 1];
					}
					else {
						dp[k][i][j] = max(dp[k][i+1][j], dp[k][i][j-1]);
						if (k > 0) {
							dp[k][i][j] = max(dp[k][i][j], 2 + dp[k-1][i+1][j - 1]);
						}
					}
				}
			}
		}

		cout << dp[K][0][n - 1] << endl;
	}

public:
	Solve() { solve(); }
};

int main(int argc, char* argv[]) {
	unique_ptr<Solve> solve = make_unique<Solve>();
	return 0;
}
