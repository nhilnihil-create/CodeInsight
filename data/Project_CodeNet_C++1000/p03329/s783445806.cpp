#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
const int INF = 1000000000;
typedef pair<int, int> P;
const int MAX_N = 1000000;
typedef int64_t ll;
template<class T> inline bool chmax(T & a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T & a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
	int N;
	cin >> N;
	int res = N;
	for (int i = 0; i <= N; i++)
	{
		int cc = 0;
		int t = i;
		while (t > 0)cc += t % 6, t /= 6;
		t = N - i;
		while (t>0) cc += t % 9, t /= 9;
		if (res > cc)res = cc;
	}
	cout << res << endl;
}