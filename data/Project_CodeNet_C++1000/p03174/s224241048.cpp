#include <iostream>
#include <vector>
#define ll long long
#define MOD 1e9+7
using namespace std;

ll getNumberOfPairs(vector<vector<bool>> compatibility,int n) {
	ll res=0;
	vector<ll> dp(1<<n);
	dp[0]=1;
	for(int mask=0;mask<(1<<n)-1;mask++) {
		int men=__builtin_popcount(mask);
		for(int women=0;women<n;women++) {
			if(compatibility[men][women] && !(mask&(1<<women))) {
				int partner=mask^(1<<women);
				dp[partner]+=dp[mask];
				dp[partner]%=(ll)MOD;
			}
		}
	}
	res=dp[(1<<n)-1];
	return res;
}

int main() {
	int n=0;
	cin>>n;
	vector<vector<bool>> compatibility(n,vector<bool>(n,false));
	int tmp=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin>>tmp;
			compatibility[i][j]=tmp==0?false:true;
		}
	}
	cout<<getNumberOfPairs(compatibility,n)<<endl;
	return 0;
}