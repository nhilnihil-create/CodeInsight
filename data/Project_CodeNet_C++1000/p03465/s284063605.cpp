#include<bits/stdc++.h>
using namespace std;
bitset<4000020>dp;
int n,x,s;
int main(void){
    scanf("%d",&n);
    dp[0]=1;
    for(int i=0;i<n;++i){
    	scanf("%d",&x);
    	dp|=dp<<x;
    	s+=x;
    }
    for(int i=(s+1)/2;i<=s;++i){
        if(dp[i]){
            printf("%d",i);
            break;
        }
    }
}
