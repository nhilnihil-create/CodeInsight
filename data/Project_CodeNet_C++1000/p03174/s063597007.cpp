#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define all(n) (n).begin(),(n).end()
#define pb push_back
#define IOS ios::sync_with_stdio(0),cin.tie(0);
ll dp[25][2100000],n;
bool ok[25][25];
const ll mod = 1000000007;

int main(){
	cin>>n;
	int all = 1<<n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>ok[i][j];
		}
	}
	for(int j=0;j<n;j++) if(ok[0][j]) dp[0][1<<j]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<all;j++){
			if(dp[i][j]){
				for(int k=0;k<n;k++){
					if( ok[i+1][k] && !(j&(1<<k)) ){
						dp[i+1][j|(1<<k)] = (dp[i+1][j|(1<<k)] + dp[i][j]) % mod; 
					}
				}
			}
		}
	}
	cout<<dp[n-1][all-1]<<'\n';
}
