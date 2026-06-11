#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits.h>
#include <queue>
#include <map>
#include <ctime>
#include <set>
 
#define rip(i,n,s) for (int i=(s);i<(int)(n);i++)
#define all(a) a.begin(),a.end()
 
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> co(200000,0),dp(n,0),da(n);
	int c;
	cin >> c;
	da[0]=c;
	dp[0]=1;
	co[c-1]=1;
	rip(i,n,1){
		cin >> c;
		da[i]=c;
		dp[i]=dp[i-1];
		if(da[i]!=da[i-1]){
			dp[i]=(co[c-1]+dp[i])%1000000007;
			co[c-1]=(dp[i-1]+co[c-1])%1000000007;
		}
	}
	cout << dp[n-1] << endl;
	//deb(dp);
}