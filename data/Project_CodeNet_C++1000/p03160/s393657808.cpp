#include <bits/stdc++.h>
using namespace std;
#define F(i,a,n) for(int i=a;i<n;i++)
#define pb push_back
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef long long ll;
#define mod 1000000007
int main()
{	
/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif*/
	int w=1;
	// cin>>w;
	while(w--){
		int n;
		cin>>n;
		vi v(n);
		F(i,0,n){
			cin>>v[i];
		}
		vi dp(n);
		dp[0]=0;
		dp[1]=abs(v[0]-v[1]);
		F(i,2,n){
			dp[i]=min(dp[i-2]+abs(v[i]-v[i-2]),dp[i-1]+abs(v[i]-v[i-1]));
		}
		cout<<dp[n-1];
	}
}