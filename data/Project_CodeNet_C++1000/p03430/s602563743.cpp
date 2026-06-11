#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int main()
{
	string s;
	int k;
	cin>>s; cin>>k;
	int n=s.size();
	int dp[301][301][301]={};
	for(int l=0; l<=k; l++){
		for(int i=0; i<n; i++){
			dp[l][i][i+1]=1;
		}
	}
	for(int d=2; d<=n; d++){
		for(int l=0; l<=k; l++){
			for(int i=0; i<=n-d; i++){
				if(s[i]==s[i+d-1]){
					dp[l][i][i+d]=max(dp[l][i][i+d], max(dp[l][i][i+d-1], max(dp[l][i+1][i+d], dp[l][i+1][i+d-1]+2)));
				}else{
					dp[l][i][i+d]=max(dp[l][i][i+d], max(dp[l][i][i+d-1], dp[l][i+1][i+d]));
					if(l>=1) dp[l][i][i+d]=max(dp[l][i][i+d], dp[l-1][i+1][i+d-1]+2);
				}
			}
		}
	}
	int ans=0;
	for(int l=0; l<=k; l++){
		ans=max(ans, dp[l][0][n]);
	}
	cout<<ans<<endl;
	return 0;
}
