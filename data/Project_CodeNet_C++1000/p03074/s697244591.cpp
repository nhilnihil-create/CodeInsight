#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N, K;
	cin >> N >> K;
	string S;
	cin >> S;
	int cont = 1;
	vector<pair<int, int> > seq;
	for (int i = 1; i <= N; ++i) {
		if (i == N || S[i] != S[i - 1]) {
			seq.push_back(make_pair(S[i - 1] - '0', cont));
			cont = 0;
		}
		++cont;
	}
	vector<int> sum(seq.size() + 1);
	for (int i = 0; i < seq.size(); ++i) {
		sum[i + 1] = sum[i] + seq[i].second;
	}
	int ans = 0;
	for (int i = 0; i < seq.size(); ++i) {
		int ptr = min(i + 2 * K + seq[i].first, int(seq.size()));
		ans = max(ans, sum[ptr] - sum[i]);
	}
	cout << ans << endl;
	return 0;
}