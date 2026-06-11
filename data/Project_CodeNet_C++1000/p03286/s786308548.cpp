#include <iostream>
#include <vector>
using namespace std;
int main() {
	int N;
	cin >> N;
	bool Plus = N >= 0, now = true;
	if (!Plus) N = -N;
	vector<int> Ans;
	while (N > 0) {
		if ((N & 1) == 1) Ans.push_back((2 * Plus - 1) * (2 * now - 1));
		else Ans.push_back(0);
		now = !now;
		N = N >> 1;
	}
	int digit = Ans.size();
	for (int i = 0; i < digit; i++) {
		if (Ans[i] == -1) {
			Ans[i] = 1;
			if (i == digit - 1) {
				Ans.push_back(1);
				digit++;
			}
			else Ans[i + 1]++;
		}
		if (Ans[i] == -2) {
			Ans[i] = 0;
			if (i == digit - 1) {
				Ans.push_back(1);
				digit++;
			}
			else Ans[i + 1]++;
		}
		if (Ans[i] == 2) {
			Ans[i] = 0;
			if (i == digit - 1) {
				Ans.push_back(-1);
				digit++;
			}
			else Ans[i + 1]--;
		}
	}
	if (digit == 0) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = digit - 1; i >= 0; i--) cout << Ans[i];
	cout << endl;
}