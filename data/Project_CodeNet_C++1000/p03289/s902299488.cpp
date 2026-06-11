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
	string S;
	cin >> S;
	
	if (S.at(0) != 'A') {
		cout << "WA" << endl;
		return 0;
	}

	int cnt = 0;
	int check;
	for (int i = 2; i < S.size()-1; i++)
	{
		if (S.at(i)=='C')
		{
			cnt++;
			check = i;
		}
	}

	if (cnt==1)
	{
		for (int i = 1; i < S.size(); i++)
		{
			if (i == check)continue;
			
			if (S.at(i)< 'a' || S.at(i)>'z')
			{
				cout << "WA" << endl;
				return 0;
			}

			
		}
		cout << "AC" << endl;
		return 0;
	}
	cout << "WA" << endl;
	return 0;
}