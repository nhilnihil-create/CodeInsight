#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1e9+7;
const int INF=1e9;
const ll LINF=(ll)1e18;

int main(){
    int n;
    cin>>n;
    vector<int> a(1<<n);
    for(int i=0;i<1<<n;i++){
        cin>>a[i];
    }
    vector<pair<int,int>> dp1(1<<n);
    for(int i=0;i<1<<n;i++){
        dp1[i]=make_pair(a[i],i);
    }
    vector<pair<int,int>> dp2(1<<n,make_pair(-INF,-INF));
    for(int i=0;i<1<<n;i++){
        for(int j=0;j<n;j++){
            if(i&(1<<j))continue;
            int to=i+(1<<j);
            if(dp1[to]<dp1[i]){
                dp2[to]=dp1[to];
                dp1[to]=dp1[i];
            }
            else if(dp1[to]==dp1[i]);
            else if(dp2[to]<dp1[i]){
                dp2[to]=dp1[i];
            }
            if(dp1[to]<dp2[i]){
                dp2[to]=dp1[to];
                dp1[to]=dp2[i];
            }
            else if(dp1[to]==dp2[i]);
            else if(dp2[to]<dp2[i]){
                dp2[to]=dp2[i];
            }
        }
    }
    int ans=-INF;
    for(int k=1;k<1<<n;k++){
        ans=max(ans,dp1[k].first+dp2[k].first);
        cout<<ans<<endl;
    }
}
