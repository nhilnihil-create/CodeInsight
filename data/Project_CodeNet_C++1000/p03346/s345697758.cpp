#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> Q(N);
	for (int i = 0; i < N; i++) {
		int P;
		cin >> P;
		Q[P - 1] = i;
	}
	int ans = 0, before = Q[0], num = 1;
	for (int i = 1; i < N; i++) {
		if (before < Q[i]) num++;
		else {
			ans = max(ans, num);
			num = 1;
		}
		before = Q[i];
	}
	ans = max(ans, num);
	cout << N - ans << endl;

}