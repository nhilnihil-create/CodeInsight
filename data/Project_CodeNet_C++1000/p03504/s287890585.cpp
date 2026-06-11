#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int N, C;
	cin >> N >> C;
	vector<vector<int>> Data(N, vector<int>(3));
	for (int i = 0; i < N; i++) cin >> Data[i][0] >> Data[i][1] >> Data[i][2];

	sort(Data.begin(), Data.end());

	using P = pair<int, int>;
	priority_queue<P,vector<P>,greater<P>> Q;
	
	int ans = 1, amari = 0;
	vector<P> unused;
	Q.push({ Data[0][1],Data[0][2] });
	for (int i = 1; i < N; i++) {
		int s = Data[i][0], t = Data[i][1], c = Data[i][2];
		
		while (!Q.empty() && Q.top().first <= s) {
			if (Q.top().second != c && Q.top().first == s) unused.push_back(Q.top());
			else amari++;
			Q.pop();
		}

		if (amari > 0) amari--;
		else ans++;

		for (auto p : unused) Q.push(p);
		unused.clear();

		Q.push({ t,c });
	}
	cout << ans << endl;
}