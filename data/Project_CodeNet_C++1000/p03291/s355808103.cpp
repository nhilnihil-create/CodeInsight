#include <iostream>
#include <string>
using namespace std;
typedef long long int ll;

ll mod=1e9+7;
ll dp[100100][4];

//dp[][0],dp[][1],dp[][2],dp[][3]

int main(){
	string s; cin >> s;
	int n=s.size();
	dp[0][0]=1;
	for(int i=0;i<n;i++){
		if(s[i]=='?'){
			for(int j=0;j<4;j++){
				(dp[i+1][j]+=dp[i][j]*3)%=mod;
				if(j<3)(dp[i+1][j+1]+=dp[i][j])%=mod;
			}
		}
		else{
			for(int j=0;j<4;j++){
				(dp[i+1][j]+=dp[i][j])%=mod;
			}
			if(s[i]=='A'){
				(dp[i+1][1]+=dp[i][0])%=mod;
			}
			if(s[i]=='B'){
				(dp[i+1][2]+=dp[i][1])%=mod;
			}
			if(s[i]=='C'){
				(dp[i+1][3]+=dp[i][2])%=mod;
			}
		}
	}
	cout << dp[n][3] << endl;
}