#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
const int INF = 100000000;
typedef pair<int, int> P;

const int L = 753;
string S;
int ans = INF;

int main() {
	cin >> S;
	rep(i, S.size()-2) {
		string M = "";
		for (int j = i; j < i+3; j++)
		{
			M += S.at(j);
			
		} 
		int tmp = stoi(M);
		ans = min(ans, abs(tmp - L));
	}
	cout << ans << endl;
}