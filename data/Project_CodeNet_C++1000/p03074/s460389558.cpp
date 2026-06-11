#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;


int main()
{
	int N, K;
	string S;
	cin >> N >> K >> S;
	vector<int> V[2];
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		cnt++;
		if (S[i] != S[i + 1]) {
			V[S[i] - '0'].push_back(cnt);
			cnt = 0;
		}
	}
	int ans = 0;
	if (V[0].size() <= K) {
		cout << N << endl;
		return 0;
	}
	for (int i = 0; i < K; i++) {
		ans += V[0][i] + V[1][i];
	}
	int p = 0;
	if (S[0] == '1') {
		ans += V[1][K];
		p++;
	}
	int sum = ans;
	for (int i = 0; i < V[0].size() - K; i++) {
		sum -= V[0][i];
		if (i - (1 - p) >= 0) sum -= V[1][i - (1 - p)];
		sum += V[0][i + K];
		if (i + K + p < V[1].size()) sum+= V[1][i + K + p];
		ans = max(ans, sum);
	}
	cout << ans << endl;
}
