//Krunal_Mathukiya
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define li long int
#define pb push_back
#define mkp make_pair
#define nikalL return
#define chalavo continue
#define basHo break
#define umap unordered_map
#define fr(i,s,n) for(int i=s;i<=n;++i)
#define frr(i,s,n) for(int i=s;i>=n;--i)
#define jaldiKarNe ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
int ns,nt;
void TestingChaluKarEyy(){
	string s,t;
	cin>>s;
	cin>>t;
	 ns=s.size();
	 nt=t.size();
	 int dp[ns+1][nt+1];
	 fr(i,0,ns) fr(j,0,nt) dp[i][j]=0;
	 fr(i,1,ns) {
	 	fr(j,1,nt) {
	 		dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	 		if(s[i-1]==t[j-1]) {
	 			dp[i][j]=max(dp[i][j],1+dp[i-1][j-1]);
	 			continue;
	 		}
	 	}
	 }
	int i=ns,j=nt;
	string ans="";
	while(i&&j) {
		if(dp[i][j]==(dp[i-1][j-1]+1) && s[i-1]==t[j-1]) {
			ans+=s[i-1];
			--i;
			--j;
		}
		else if(dp[i-1][j]==dp[i][j]) --i;
		else if(dp[i][j-1]==dp[i][j]) --j;
	}
	reverse(ans.begin(),ans.end());
	cout<<ans;
}
int main(){
//	#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	#endif
	// jaldiKarNe;
	int TestingKaravvuChhe=1;
	// cin>>TestingKaravvuChhe;
	while(TestingKaravvuChhe--){
		TestingChaluKarEyy();
	}
}