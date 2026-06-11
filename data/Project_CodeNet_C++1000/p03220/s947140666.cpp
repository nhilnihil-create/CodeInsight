#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
const int INF = 1000000000;
typedef pair<int, int> P;
const int MAX_N = 1000000000;
typedef int64_t ll;
template<class T> inline bool chmax(T & a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T & a, T b) { if (a > b) { a = b; return 1; } return 0; }




int main() {
	int N, T, A;
	cin >> N >> T >> A;
	int buf = 1<<30;
	int ans = 0;
	rep(i, N) {
		int tmp,h;
		cin >> h;
		tmp = abs(T*1000 - h *6 - A*1000);
		if (buf>tmp)
		{
			buf = tmp;
			ans = i + 1;
		}
	}
	cout << ans << endl;
}