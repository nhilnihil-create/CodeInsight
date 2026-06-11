#include<bits/stdc++.h>

#define X first
#define Y second
#define ll long long
#define MP make_pair
#define PB push_back

using namespace std;

const int MAXN=1e5;
ll MOD=1e9+7;

ll n,a,b;
ll bio[MAXN+5];
vector <ll> sus[MAXN+5];
ll dp[3][MAXN+5];

void resi(ll x){
	dp[0][x]=1;
	dp[1][x]=1;
	bio[x]=1;
	for(int i=0; i<sus[x].size(); i++){
		if(bio[sus[x][i]]==0){
			resi(sus[x][i]);
			dp[0][x]*=(dp[0][sus[x][i]]+dp[1][sus[x][i]]);
			dp[0][x]%=MOD;
			dp[1][x]*=(dp[0][sus[x][i]]);
			dp[1][x]%=MOD;
		}
	}
}

int main () {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;
	for(int i=0; i<n-1; i++){
		cin>>a>>b;
		sus[a].PB(b);
		sus[b].PB(a);
	}
	resi(1);
	cout<<(dp[0][1]+dp[1][1])%MOD;
	
	return 0;
}