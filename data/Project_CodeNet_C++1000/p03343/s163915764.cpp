#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(V) V.begin(),V.end()
const ll MOD = 1000000007;

int main() {
	int N, K, Q;
	cin >> N >> K >> Q;
	vector<int> A(N), C(N);
	vector<pair<int, int>> B(N);
	for (int i = 0;i < N;i++) {
		cin >> A[i];
		B[i] = { A[i],i };
	}
	sort(all(B));
	for (int i = 0;i < N;i++) {
		C[i] = B[i].second;
	}
	int ans = INT32_MAX;
	set<int> S;
	S.insert(-1);
	S.insert(N);
	vector<int> V;
	priority_queue<int> P, PS;
	for (int i = 0;i < N;i++) {
		V = A;P = PS;
		for (auto it = S.begin();it != S.end();it++) {
			auto it2 = it;it2++;
			if (*it2 != *it + 1) {
				sort(V.begin() + *it + 1, V.begin() + *it2);
			}
			if (*it2 >= N)break;
			V[*it2] = -1;
		}
		int cnt = 0;
		for (int j = N - 1;j >= 0;j--) {
			if (V[j] < 0) {
				cnt = 0;
				continue;
			}
			cnt++;
			if (cnt > K - 1) {
				P.push(-V[j]);
			}
		}

		if (P.empty())break;
		int f = -P.top(), s;
		for (int j = 0;j < Q - 1;j++) {
			if (P.empty())
				break;
			P.pop();
		}
		if (P.empty())break;
		s = -P.top();
		ans = min(ans, s - f);
		S.insert(C[i]);
	}
	cout << ans << endl;
}