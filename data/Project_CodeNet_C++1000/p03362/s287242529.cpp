#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> IsPrime(55556, 1), Ans;
	for (int i = 2; i <= 55555; i++) {
		if (!IsPrime[i]) continue;
		else {
			int j = i + i;
			while (j <= 55555) {
				IsPrime[j] = 0;
				j += i;
			}
			if (i % 5 == 1) Ans.push_back(i);
		}
	}

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cout << Ans[i] << endl;
}