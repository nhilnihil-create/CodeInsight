#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
typedef int64_t ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main() {
	string N;
	cin >> N;
	
	bool ok = true;
	for (int i = 1; i < N.size(); i++)
	{
		if (N.at(i)!='9')
		{
			ok = false;
		}
	}

	if (ok)
	{
		cout << N.at(0) - '0' + 9 * N.size() - 9 << endl;
	}
	else {
		cout << N.at(0) - '1' + 9 * N.size() - 9 << endl;
	}
}