#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dp[3005][3005];

string LCS(string s, string t){
	int n = s.size();
	int m = t.size();
	rep(i,n)rep(j,m){
		if(s[i] == t[j]) chmax(dp[i+1][j+1], dp[i][j] + 1);
		chmax(dp[i+1][j+1], dp[i+1][j]);
		chmax(dp[i+1][j+1], dp[i][j+1]);
	}
	string res = "";
	int i = n, j = m;
	while(i > 0 && j > 0){
		if(dp[i][j] == dp[i-1][j]) --i;
		else if(dp[i][j] == dp[i][j-1]) --j;
		else{
			res = s[i-1] + res;
			--i; --j;
		}
	}
	return res;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s, t;
	cin >> s >> t;
	cout << LCS(s, t) << endl;
	return 0;
}