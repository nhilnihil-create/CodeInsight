#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.size();
    vector<int> alphabit(n+1);
    for(int i=0;i<n;i++){
        alphabit[i+1]=alphabit[i]^(1<<(s[i]-'a'));
    }
    
    vector<int> dp(n+1,n);
    dp[0]=0;
    map<int,int> mp;
    mp[0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<='z'-'a';j++){
            int v=alphabit[i+1]^(1<<j);
            if(mp.count(v)){
                // cerr<<i<<" "<<char(j+'a')<<" "<<mp[v]<<endl;
                dp[i+1]=min(dp[i+1],dp[mp[v]]+1);
            }
        }
        if(mp.count(alphabit[i+1])){
            // cerr<<"#"<<endl;
            dp[i+1]=min(dp[i+1],dp[mp[alphabit[i+1]]]);
        }
        // cerr<<"$"<<dp[i+1]<<endl;
        mp[alphabit[i+1]]=i+1;
    }
    cout<<max(dp[n],1)<<endl;
    return 0;
}