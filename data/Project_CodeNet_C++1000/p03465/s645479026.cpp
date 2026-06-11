#include<bitset>
#include<iostream>
using namespace std;
bitset<2000007>dp;
int main(){
	int n;
    cin>>n;
    int sum=0;
    dp[0]=1;
    for(int i=1;i<=n;i++){
    	int x;
        cin>>x;
        dp|=dp<<x;
        sum+=x;
    }
    for(int i=(sum+1)>>1;i<=sum;i++){
        if(dp[i]){
			cout<<i<<endl;
			break;
		}
    }
    return 0;
}