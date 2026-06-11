#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
const int INF = 100000000;
typedef pair<int, int> P;
const int MAX_N = 1000000;

int N, M;
vector<int> vec(MAX_N);

int main() {
	cin >> N >> M;
	int L = 1; int R = MAX_N;
	int tmpL, tmpR;
	rep(i, M) {
		cin >> tmpL;
		L = max(L, tmpL);
		cin >> tmpR;
		R = min(R, tmpR);
	}

	int ans = 0;
	for (int i = L; i <= R; i++)
	{
		ans++;
	}
	cout << ans << endl;
}