#include<bits/stdc++.h>
using namespace std;
//Credits: errichto
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define fr(i,k,n) for (int i = k; i < n; ++i)
#define fri(i,k,n) for (int i = k; i >= n; --i)
#define INF (int)1e9
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define all(arr) arr.begin(),arr.end()

void boost(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int N=3003;
ll dp[2][N];

void solve(){
	dp[1][1]=1;
	int n;
	cin>>n;
	string s;
	cin>>s;
	int t=0;
	fr(i,2,n+1){
		fr(j,0,i+1)
			dp[t][j]=0;
		fr(j,1,i+1){
			if(s[i-2]=='<')
				dp[t][j]=(dp[t][j]+ (dp[t^1][j-1]) +MOD)%MOD;
			else
				dp[t][j]=(dp[t][j]+ (dp[t^1][i-1]-dp[t^1][j-1]) + MOD)%MOD;
		}
		fr(j,1,i+1)
			dp[t][j]=(dp[t][j]+dp[t][j-1])%MOD;
		t^=1;
	}
	cout<<dp[t^1][n]<<endl;
	return;
}

int main()
{
	boost();
	
	int tc=1;
	//cin>>tc;
	while(tc--)
		solve();
	return 0;
}