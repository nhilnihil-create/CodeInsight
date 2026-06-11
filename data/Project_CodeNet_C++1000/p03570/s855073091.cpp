#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int M{200001};
char s[M];
int b,i,h[1<<26],dp[M];
int main(){
    scanf("%s",s);
    fill_n(dp,M,M);
    fill_n(h,1<<26,M);
    for(dp[0]=h[0]=0;s[i];++i){
        b^=1<<(s[i]-'a');
        dp[i+1]=min(dp[i+1],h[b]+1);
        for(int j{};j<26;++j)
            dp[i+1]=min(dp[i+1],h[b^(1<<j)]+1);
        h[b]=min(h[b],dp[i+1]);
    }
    printf("%d\n",dp[i]);
}
