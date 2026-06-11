#include<bits/stdc++.h>

#define X first
#define Y second
#define ll long long
#define MP make_pair
#define PB push_back

using namespace std;

ll MOD=1e9+7;
ll n,k;
ll niz[105];
ll dp[105][100005];
ll ps[100005];
ll br;
ll pom;

int main () {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>n>>k;
	for(int i=0; i<n; i++){
		cin>>niz[i];
	}
	niz[n]=3;
	ps[k+1]=1;
	ps[max(pom,k-niz[0])]=-1;
	for(int i=0; i<n; i++){
		br=0;
		for(int j=k+1; j>=0; j--){
			dp[i][j]=br;
			dp[i][j]%=MOD;
			br+=ps[j];
	//		cout<<i<<" "<<j<<" "<<dp[i][j]<<" "<<ps[j]<<"\n";
		}
		for(int j=k+1; j>=0; j--){
			ps[j]=0;
		}
		for(int j=k; j>=0; j--){
			ps[j+1]+=dp[i][j];
			ps[max(pom,j-niz[i+1])]+=-dp[i][j];
	//		cout<<j-niz[i+1]<<"\n";
		}
	}
	cout<<dp[n-1][0];
	
	return 0;
}