/*@author Vipen Loka*/
#include <bits/stdc++.h>
#define endl '\n'
#define ff first
#define ss second
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define deb(x) cout << #x << ':' << x << '\n';

using namespace std;

void solve(){
	int i,j;
	string a,b;
	cin >> a >> b;
	int x=a.size(),y=b.size();
	vector<vector<int>> dp(x+1,vector<int>(y+1,0));

	for (int i = 1; i < x+1; ++i)
	{
		for (int j = 1; j < y+1; ++j)
		{
			if(a[i-1]==b[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}

	// printf("%d\n",dp[x][y]);
	i=x;j=y;
	string ans;
	// for(auto x:dp){
	// 	for(auto y:x){
	// 		cout << y << ' ';
	// 	}
	// 	cout << endl;
	// }
	while(i>0 && j>0){
		if(dp[i][j-1]==dp[i][j]){
			j--;
		}
		else if(dp[i-1][j]==dp[i][j]){
			i--;
		}
		else{
			ans=a[i-1]+ans;
			i--;
			j--;
		}
	}

	cout << ans << endl;
}


int main(){
	int T=1;
	// cin >> T;
	while (T--){
		solve();
	}
}
