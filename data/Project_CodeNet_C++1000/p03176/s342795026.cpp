//optimised approach O(nlogn)
#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
int32_t main(){
    int n;
    cin>>n;
    int h[n+1];
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>h[i];    
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];    
    }
    int dp[n+1];
    map<int,int> hm;
    dp[1]=a[1];
    hm[h[1]]=a[1];
    for(int i=2;i<=n;i++){
        dp[i]=a[i];
        auto it=hm.upper_bound(h[i]);
        if(it!=hm.begin()){
            it--;
            dp[i]=max(dp[i],a[i]+it->second);
        }
        hm[h[i]]=dp[i];
        it=hm.upper_bound(h[i]);
        while(it!=hm.end() && dp[i]>=it->second){
            auto tmp=it;
            it++;
            hm.erase(tmp);
        }
    }
    cout<<*max_element(dp+1,dp+n+1)<<endl;
    return 0;
}
