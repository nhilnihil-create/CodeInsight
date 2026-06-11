//Krunal_Mathukiya
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define li long int
#define pb push_back
#define mkp make_pair
#define nikalL return
#define umap unordered_map
#define fr(i,s,n) for(int i=s;i<=n;++i)
#define frr(i,s,n) for(int i=s;i>=n;--i)
#define jaldiKarNe ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
int n,m;
int grid[1001][1001];
int vis[1001][1001];
int dp[1001][1001];
lli fn(int i,int j) {
	if(!grid[i][j]) return 0;
	if(i==0 || j==0) return 0;
	if(i==1 && j==1) return 1;
	if(vis[i][j]) return dp[i][j];
	vis[i][j]=1;
	lli curr=fn(i-1,j)+fn(i,j-1);
	curr%=mod;
	return dp[i][j]=curr;
}
void TestingChaluKarEyy(){
	cin>>n>>m;
	fr(i,1,n) {
		fr(j,1,m) {
			char ch;
			cin>>ch;
			if(ch=='.') grid[i][j]=1;
		}
	}
	cout<<fn(n,m);

}
int main(){
	jaldiKarNe;
	int TestingKaravvuChhe=1;
//	cin>>TestingKaravvuChhe;
	while(TestingKaravvuChhe--){
		TestingChaluKarEyy();
	}
}
