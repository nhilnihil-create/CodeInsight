#include<bits/stdc++.h>
using namespace std;
int n,sum,x;
bitset<4000010> dp;
int main(){
    cin>>n;
    dp[0]=1;
    for(int i=0;i<n;i++){
		cin>>x;
		sum+=x;
		dp|=dp<<x;
	}
    for(int i=(sum+1)/2;i<=sum;i++)
        if(dp[i]){
            cout<<i;
            return 0;
        }
    return 0;
}