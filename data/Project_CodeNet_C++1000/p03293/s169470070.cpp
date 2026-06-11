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
	string S, T; cin >> S >> T;
	bool ans = false;
	for (int i = 0; i < S.size(); i++)
	{
		if (S == T) {
			ans = true;
			break;
		}
		S = S.back() + S.substr(0, S.size() - 1);
	}
	if (ans)
	{
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}