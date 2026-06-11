#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int dp[200000],ch[200000],a,n,ans=1,b,MOD=1000000007;
vector<int> v;
int main(void){
    cin>>n;
    
    cin>>a;
    v.push_back(a);
    for(int i=1;i<n;i++){
        cin>>b;
        if(a!=b){
            v.push_back(b);
        }
        a=b;
    }
    n=v.size();
    
    memset(ch,-1,sizeof(ch));
    for(int i=0;i<n;i++){
        a=v[i];
        a--;
        if(ch[a]==-1)ch[a]=i;
        else{
            ans+=dp[ch[a]]+1;
            ans%=MOD;
            dp[i]=dp[ch[a]]+1;
            ch[a]=i;
        }
        if(i!=0)dp[i]+=dp[i-1];
        dp[i]%=MOD;
        //cout<<ans<<" "<<dp[i]<<endl;
    }
    cout<<ans<<endl;
}
