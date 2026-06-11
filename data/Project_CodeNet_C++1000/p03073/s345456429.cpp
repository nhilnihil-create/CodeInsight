#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
const int INF = 100000000;
typedef pair<int, int> P;
const int MAX_N = 1000000;

string S;

int main() {
	cin >> S;
	int tmp = 0;
	rep(i, S.size()) {
		if (i % 2 == 0)
		{
			if (S.at(i) == '0')tmp++;
		}
		else {
			if (S.at(i) == '1')tmp++;

		}
	}
	if (tmp > S.size() - tmp)cout << S.size() - tmp << endl;
	else cout << tmp << endl;
	
}