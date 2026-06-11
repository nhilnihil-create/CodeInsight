#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=1e4+5,M=1e9+7,mxW=2e4+5;
//did u check when n=1?
//is mxN correct?
int dp[mxW],n;
struct t{
    int  w,s,v;
    bool operator<(const t &o) const{
        return w+s<o.w+o.s;
    }
} a[mxN];
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].w>>a[i].s>>a[i].v;
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        for(int j=a[i].s;j>=0;j--){
            dp[j+a[i].w]=max(dp[j+a[i].w],dp[j]+a[i].v);
        }
    }
    int ans=0;
    for(int i=0;i<mxW;i++)ans=max(ans,dp[i]);
    cout<<ans;


}