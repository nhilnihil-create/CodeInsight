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
	string S, T;
	cin >> S >> T;
	
	if (S==T)
	{
		cout << "Yes" << endl;
		return 0;
	}
	for (int i = S.size()-1; i >= 1; i--)
	{
		string U;
		for (int j = i; j < S.size(); j++)
		{
			U.push_back(S.at(j));
		}
		for (int k = 0; k < i; k++)
		{
			U.push_back(S.at(k));
		}
		
		bool ok = true;
		rep(m, T.size()) {
			
			if (T.at(m) != U.at(m)) {
				ok = false;
				break;
			}		
		}
		if (ok) {
			cout << "Yes" << endl;
			return 0;
		}
		
	}
	cout << "No" << endl;
}