#pragma GCC optimize ("O2")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int M{200001};
unordered_map<int,int> m;
char s[M];
int b,i,dp[M];
inline int h(int a){
    auto p=m.find(a);
    return p!=m.end()?p->second:M;
}
int main(){
    scanf("%s",s);
    fill_n(dp,M,M);
    m.reserve(M*26);
    for(dp[0]=m[0]=0;s[i];++i){
        b^=1<<(s[i]-'a');
        dp[i+1]=min(dp[i+1],h(b)+1);
        for(int j{};j<26;++j)
            dp[i+1]=min(dp[i+1],h(b^(1<<j))+1);
        if(h(b)>dp[i+1])m[b]=dp[i+1];
    }
    printf("%d\n",dp[i]);
}
