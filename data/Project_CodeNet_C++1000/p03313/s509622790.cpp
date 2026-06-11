//============================================================================
// Name        : training.cpp
// Author      : CoNKeR The Red Squirrel
//============================================================================
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
	cin >> n;

	n = 1 << n;

	vector<int> A(n);
	for(int &x : A) { cin >> x; }

	vector<pair<int, int>> dp(n, {INT32_MIN, INT32_MIN});
	int sol = INT32_MIN;

	for(int i = 1; i < n; ++i) {
        set<int> choices;
		for(int mask = 1; mask <= i; mask <<= 1) {
			if(i & mask) {
				int sm = i ^ mask;
				if(sm < n) {
                    choices.insert(dp[sm].first);
                    choices.insert(dp[sm].second);
				}
			}
		}

		int first = i, second = 0;
		for(int j : choices) {
            if(j < 0) { continue; }
            if(A[j] > A[first]) { second = first, first = j; }
            else if(A[j] > A[second]) { second = j; }
		}

		sol = max(sol, A[first] + A[second]);
		dp[i] = {first, second};

		cout << sol << "\n";
	}

    return 0;
}