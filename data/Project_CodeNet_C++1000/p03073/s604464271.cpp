//Author: Fuadul Hasan(fuadul202@gmail.com)
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N   = 2e5 + 5;
int dp[N],dp1[N];
int main(){
	
	string s;
	cin>>s;
	int n = s.size();
	for(int i=1;i<=n;i++){
		dp[i] = dp[i-1]^1;
	}

	dp1[1] = 0;
	for(int i=2;i<=n;i++){
		dp1[i] = dp1[i-1]^1;
	}
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(s[i]-'0' != dp[i+1])cnt++;
	}	

	int cnt1 = 0;

	for(int i=0;i<n;i++){
		if(s[i]-'0' != dp1[i+1])cnt1++;
	}	

	cout<<min(cnt,cnt1)<<endl;
	

	return 0;
}