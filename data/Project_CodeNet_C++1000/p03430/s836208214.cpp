#include <bits/stdc++.h>

using namespace std;


int n, k;
string str;
int dp[302][302][151];

int recur(int st, int en, int left){
	if(st == en) return 1;
	if(st > en) return 0;
	if(dp[st][en][left] != -1) return dp[st][en][left];
	int ret = 0;
	if(str[st] == str[en]) ret = max(ret, 2 + recur(st + 1, en - 1, left));
	ret = max(ret, recur(st + 1, en, left));
	ret = max(ret, recur(st, en - 1, left));
	if(left) ret = max(ret, 2 + recur(st + 1, en - 1, left - 1));
	return dp[st][en][left] = ret;
}

int main(){
	cin >> str;
	cin >> k;
	n = str.size();
	memset(dp, -1, sizeof(dp));
	cout << recur(0, n - 1, min(k, 150)) << endl;
	return 0;
}
