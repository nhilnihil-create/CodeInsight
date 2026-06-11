#include <iostream>
#include <vector>
using namespace std;

#define rep(i,b,e) for(auto i=b;i<e;i++)

typedef long long ll;

int main(){
	int n;
	cin>>n;
	
	int a[n][n];
	rep(i,0,n) 
		rep(j,0,n)
			cin>>a[i][j];
		
	vector <ll> dp(1<<n,0);
	
	rep(group,0,(1<<n))
		rep(i,0,n)
			if(group&(1<<i))
				rep(j,i+1,n)
					if(group&(1<<j))
						dp[group]+=a[i][j];
	//O(2ⁿn²)
						
	rep(mask,0,(1<<n))
		for(int submask=mask;submask;submask=(submask-1)&mask)
			dp[mask]=max(dp[mask],dp[submask]+dp[submask^mask]);
	// O(Σ2ᵏ*ⁿCₖ) = O(3ⁿ)

	cout<<dp[(1<<n)-1]<<endl;
}

