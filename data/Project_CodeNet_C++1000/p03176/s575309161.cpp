#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct flower{
    int height;
    int bty;
};

ll solve(vector<flower> v,int n){
    ll dp[n+1];
    dp[1] = v[1].bty;
    map<ll,ll> meaningFull;
    meaningFull[v[1].height] = dp[1];
    ll ans = dp[1];
    for(int i=2;i<=n;i++){
        dp[i] = v[i].bty;
        auto it  = meaningFull.upper_bound(v[i].height);
        if(it != meaningFull.begin()){
            it--;
            dp[i] += it->second;
        }
        meaningFull[v[i].height] = dp[i];
        it = meaningFull.upper_bound(v[i].height);
        while(it != meaningFull.end() && it->second <= dp[i]){
            auto temp = it;
            temp++;
            meaningFull.erase(it);
            it = temp;
        }
        ans = max(ans,dp[i]);
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<flower> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i].height;
    }
    for(int i=1;i<=n;i++){
        cin>>v[i].bty;
    }
    cout<<solve(v,n)<<endl;
}
