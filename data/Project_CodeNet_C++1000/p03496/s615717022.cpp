#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int main()
{
	int N;
	cin >> N;
	ll Ai[N];
	rep(i, N) {
		cin >> Ai[i];
	}

	ll maxValue = 0;
	ll maxIndex = 0;

	for (int i = 0; i < N; i++) {
		if (abs(maxValue) < abs(Ai[i])) {
			maxValue = Ai[i];
			maxIndex = i;
		}
	}
	vector<string> answers;

	if (maxValue > 0) {
		for (int i = 1; i < N; i += 1) {
			while (Ai[i] < Ai[i - 1]) {
				Ai[i] += maxValue;
				answers.push_back(to_string(maxIndex + 1) + " " + to_string(i + 1));
				if (Ai[i] > maxValue) {
					maxValue = Ai[i];
					maxIndex = i;
				}
			}
		}
	} else {
		for (int i = N - 2; i >= 0; i--) {
			while (Ai[i] > Ai[i + 1]) {
				Ai[i] += maxValue;
				answers.push_back(to_string(maxIndex + 1) + " " + to_string(i + 1));
				if (Ai[i] < maxValue) {
					maxValue = Ai[i];
					maxIndex = i;
				}
			}
		}
	}
	cout << answers.size() << endl;
	for (auto ans : answers) {
		cout << ans << endl;
	}
	return 0;
}
