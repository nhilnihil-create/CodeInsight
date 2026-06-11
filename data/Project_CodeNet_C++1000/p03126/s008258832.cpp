#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
const int INF = 100000000;
typedef pair<int, int> P;
const int MAX_N = 1000000;

int N, M;
vector<int> vo(31);

int main() {
	cin >> N >> M;
	rep(i, N) {
		int K;
		cin >> K;
		rep(i, K) {
			int A;
			cin >> A;
			vo.at(A-1)++;
		}
	}
	int ans = 0;
	rep(i, 31) {
		if (vo.at(i) == N) {
			ans++;
		}
	}
	cout << ans << endl;

}
