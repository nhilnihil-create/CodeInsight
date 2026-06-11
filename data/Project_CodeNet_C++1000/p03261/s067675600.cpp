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


bool solve(const vector<string>& W) {
	const int n = W.size();

	//condition1
	for (int i = 0; i < n-1; i++)
	{
		if (W[i].back()!= W[i+1].front())
		{
			return false;
		}
	}

	//condition2
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (W[i]==W[j])
			{
				return false;
			}
		}
	}
	return true;
}

vector<string> input() {
	int n; cin >> n;
	vector<string> W(n);
	for (int i = 0; i < n; i++)
	{
		cin >> W[i];
	}
	return W;
}

int main() {
	const vector<string> W = input();
	if (solve(W))
	{
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}