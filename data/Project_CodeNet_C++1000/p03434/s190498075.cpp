#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
typedef pair<int, int> P;
typedef int64_t ll;
const int MAX_N = 10000;
const int INF = 1000000000;

int N;
int a[108];

int main() {
	cin >> N;
	rep(i, N) {
		cin >> a[i];
	}
	sort(a, a + N, greater<int>());

	int ret = 0;
	rep(i, N) {
		ret += a[i] * (i & 1 ? -1 : 1);
	}
	cout << ret << endl;
	return 0;
}