#include<bits/stdc++.h>
using namespace std;
const int maxn=2000007;
bitset<maxn> dp;
int main(){
	dp[0]=1;
	int n,sum=0,x;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		sum+=x;
		dp=dp|(dp<<x);
	}
	for(int i=(sum+1)>>1;i<=sum;i++){
		if(dp[i]) {
			cout<<i;
			break;
	    }
    }
	return 0;
}