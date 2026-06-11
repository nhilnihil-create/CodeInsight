#include <bits/stdc++.h>

using namespace std;

#define debug(x) '[' << #x << " is: " << x << "] "
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	#ifndef ONLINE_JUDGE
//		freopen("input.txt","r",stdin);
	#endif
	string s;
	int x,y;
	cin>>s>>x>>y;
	const int add = 8000;
	x+=add;
	y+=add;
	int n = s.size();
	int at=0;
	while(at < n && s[at] == 'F'){
		at++;
		x--;
	}
	int t=1;
	vector<int> g[2];
	int len = 0;
	for(int i=at+1;i<n;i++){
		if(s[i] == 'T'){
			g[t].push_back(len);
			len = 0;
			t = !t;
		}else len++;
	}
	g[t].push_back(len);
	bool can = 1;
	for(int it=0;it<2;it++){
		vector<vector<int>> dp(2,vector<int>(2*add+10,-1));
		int q = 0;
		dp[0][add] = 1;
		for(int i=0;i<g[it].size();i++){
			for(int j=2*add;j>=0;j--){
				if(dp[q][j] == -1)continue;
				dp[!q][j+g[it][i]] = 1;
				dp[!q][j-g[it][i]] = 1;
			}
			dp[q] = vector<int> (2*add+10,-1);
			q = !q;
		}
		if(it == 0 && dp[q][x] == -1)can = 0;
		if(it == 1 && dp[q][y] == -1)can = 0;
	}
	cout << (can ? "Yes" : "No") << '\n';

}