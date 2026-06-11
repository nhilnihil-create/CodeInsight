#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <functional>
#include <set>
#include <queue>
#include <cctype>
#include <climits>
#include <stack>
#include <map>
#include <cstring>
#include <cassert>
 
using namespace std;

bool check(int x){
	if(x==0) return true;
	return !(x&(x-1));
}

int main(){

	string s;
	cin>>s;

	int n=s.size();
	vector<int> dp(1<<26,1<<28);

	dp[0]=0;
	int state=0;
	for(int i=0;i<n;i++){
		state ^= (1<<(s[i]-'a'));
		for(int j=0;j<26;j++){
			dp[state] = min(dp[state],dp[state^(1<<j)]+1);
		}
	}

	cout<<max(1,dp[state])<<endl;

	return 0;
}
