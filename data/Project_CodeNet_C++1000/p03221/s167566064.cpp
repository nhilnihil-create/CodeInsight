#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
	int N, M; cin >> N >> M;
	vector<set<int>> vs(N);
	vector<int> P(M), Y(M);
	for(int i = 0; i < M; i++) {
		cin >> P[i] >> Y[i];
		P[i]--;
		vs[P[i]].insert(Y[i]);
	}
	map<pair<int, int>, int> m;
	for(int i = 0; i < N; i++) {
		int rank = 1;
		for(auto u: vs[i]) {
			pair<int, int> p = make_pair(i + 1, u);
			m[p] = rank;
			rank++;
		}
	}
	for(int i = 0; i < M; i++) {
		P[i]++;
		string S = to_string(P[i]);
		reverse(S.begin(), S.end());
		while(S.size() < 6) S += "0";
		reverse(S.begin(), S.end());
		pair<int, int> q = make_pair(P[i], Y[i]);
		string T = to_string(m[q]);
		reverse(T.begin(), T.end());
		while(T.size() < 6) T += "0";
		reverse(T.begin(), T.end());
		cout << S + T << endl;
	}
	return 0;
}
