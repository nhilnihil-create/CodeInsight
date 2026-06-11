
// D - Various Sushi

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

pair<int, int> sushi[100000];

int main() {
	int N, K;
	cin >> N >> K;

	for (int i=0; i<N; i++) {
		int t, d;
		cin >> t >> d;
		sushi[i] = make_pair(d, t);
	}

	sort(sushi, sushi+N, greater<pair<int, int>>());

	ll score = 0;
	ll x = 0;
	stack<int> A;
	queue<int> B;
	unordered_map<int, int> cnt;

	for (int i=0; i<N; i++) {
		int t = sushi[i].second;
		int d = sushi[i].first;
		cnt[t]++;

		if (i < K) {
			score += d;
			if (cnt[t] == 1) x++;
			else A.push(d);
		} else {
			if (cnt[t] == 1) B.push(d);
		}
	}

	//cout << score << endl; // **** debug ****

	score += x * x;
	ll max_score = score;
	while(1) {
		//cout << max_score << endl; // **** debug ****
		if (A.empty() || B.empty()) break;

		score -= A.top();
		//cout << " - " << A.top() << endl; // **** debug ****
		A.pop();

		score += B.front();
		//cout << " + " << B.front() << endl; // **** debug ****
		B.pop();

		score -= x * x;
		//cout << " - " << x * x << endl; // **** debug ****
		x++;
		score += x * x;
		//cout << " + " << x * x << endl; // **** debug ****

		max_score = max(max_score, score);
	}

	cout << max_score << endl;

	return 0;
}