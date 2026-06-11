#include<bits/stdc++.h>
using namespace std;

bitset<4000001> dp;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	dp[0]=1;
	int n;
	cin>>n;
	int tot=0;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		tot+=x;
		dp|=dp<<x;
	}
	for(int i=(tot+1)/2;;i++)
		if(dp[i]){
			cout<<i<<endl;
			return 0;
		}
	
}
