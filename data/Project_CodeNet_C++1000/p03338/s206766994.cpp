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
	int N;
	cin >> N;
	string S;
	cin >> S;

	int ans = 0;
	for (int i = 1; i < N; i++) {
		int cnt = 0;

		for (char c = 'a'; c <= 'z'; c++) {
			bool left = false, right = false;

			for (int j = 0; j < i; j++)
				if (S[j] == c) {
					left = true;
				}

			for (int j = i; j < N; j++) {
				if (S[j] == c) {
					right = true;
				}
			}
			if (left && right) {
				cnt++;
			}
		}
		if (ans < cnt) {
			ans = cnt;
		}
	}
		cout << ans << "\n";

		return 0;
}
