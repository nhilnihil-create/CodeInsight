#include<bits/stdc++.h>
#define ll 	 long long
#define pb push_back
#define mp make_pair
using namespace std;

#define mmm    ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MOD = 1e9 + 7;
int dp[1000][1000];
string s[1000];

int main()
{

mmm;

int n,m; cin>>n>>m;


for(int i=0; i<n; i++) 
cin>>s[i]; 

//for(int i=0; i<n; i++) 
//cout<<s[i]<<" "; 

dp[0][0]=1;

for(int i=0; i<n; i++)
{
	for(int j=0; j<m; j++)
	{
		if(i) dp[i][j] += dp[i-1][j];
		if(j) dp[i][j] += dp[i][j-1];
		dp[i][j]%=MOD ;
		
		if(s[i][j]=='#') dp[i][j]=0;
	}
}

cout<<dp[n-1][m-1]<<endl;

     return 0;
}