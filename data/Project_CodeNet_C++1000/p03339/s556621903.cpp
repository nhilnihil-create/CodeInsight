#include "bits/stdc++.h"
using namespace std;


int main() {

	int N;
	string S;
	cin >> N >> S;

	int count = 0;
	for (int i = 1;i < N;i++) {
		if (S.at(i) != 'W')
			count++;
	}
	int ans = count;
	for (int i = 1;i < N;i++) {
		if (S.at(i - 1) == 'E' && S.at(i) == 'E') {
			count--;
		}
		if (S.at(i - 1) == 'W' && S.at(i) == 'W') {
			count++;
		}
		ans = min(ans, count);
	}

	cout << ans;
}
