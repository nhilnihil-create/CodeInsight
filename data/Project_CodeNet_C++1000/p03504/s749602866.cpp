#include<iostream>
#include<vector>
using namespace std;

int N, C;
vector<int>s(100005), t(100005), c(100005), sum(200005), tt(200005);

int main() {
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> s[i] >> t[i] >> c[i];
	}

	for (int i = 1; i <= C; i++) {
		for (int j = 0; j < 200005; j++)tt[j] = 0;
		for (int j = 0; j < N; j++)if (c[j] == i)tt[s[j] * 2 - 1]++, tt[t[j] * 2]--;
		for (int j = 1; j < 200005; j++)tt[j] += tt[j - 1];
		for (int j = 0; j < 200005; j++)if (tt[j] > 0)sum[j]++;
	}
	int maxNum = 0;
	for (int i = 0; i < 200005; i++)if (maxNum < sum[i])maxNum = sum[i];
	cout << maxNum << endl;

	return 0;
}