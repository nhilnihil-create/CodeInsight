#include <bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define pb push_back
#define ff first 
#define ss second
#define mod 1000000007
#define lim 100005
#define nfs_mw ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int dp[1<<18][2];
void merge(int big[2], int small[2])
{
	for(int i=0; i<2; i++){
		if(small[i]>big[1]) big[1] = small[i];
		if(big[0]<big[1]) swap(big[0], big[1]);
	}
}


int main()
{
	nfs_mw;
	int i,j,n,mask,out = 0;
	cin>>n;
	for(i=0; i<(1<<n); i++) cin>>dp[i][0];

	for(i=0; i<n; i++)
		for(mask=0; mask<(1<<n); mask++) if(mask&(1<<i))
			merge(dp[mask], dp[mask^(1<<i)]);

	for(i=1; i<(1<<n); i++) cout<<(out = max(out, dp[i][0] + dp[i][1]))<<"\n";

	return 0;
}