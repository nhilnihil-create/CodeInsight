#include <bits/stdc++.h>
using namespace std;
const int N = 1<<26;
string s;
int dp[N + 10];
int main(){
	//freopen("readin.txt","r",stdin);
	cin >> s;
	int have = 0;
	for(int i = 0;i < (1<<26);i++)dp[i] = 1e6;
	for(auto i : s){
		have^=1<<(i - 'a');
		if(!(have&(have - 1)))dp[have] = 1;
		for(int j = 0;j < 26;j++)dp[have] = min(dp[have],1 + dp[have^(1<<j)]);
	}
	cout << dp[have] << endl;
}