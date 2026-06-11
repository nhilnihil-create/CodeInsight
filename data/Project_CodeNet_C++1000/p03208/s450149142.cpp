#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
const int INF = 1000000000;
typedef pair<int, int> P;
const int MAX_N = 1000000000;
const int MAX_E = 100000000;
const int MAX_V = 10000;
typedef int64_t ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main() {
	int K, N;
	cin >> N >> K;
	vector<int> vec(N);
	rep(i, N) {
		cin >> vec.at(i);
	}
	sort(vec.begin(), vec.end());
	int ans = INF;
	for (int i = 0; i <= N - K; i++) {
		ans = min(ans, abs(vec.at(i) - vec.at(i + K-1)));
	}
	cout << ans << endl;
}