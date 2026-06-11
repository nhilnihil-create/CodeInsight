#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;

bool comp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    int s=a.first.first+a.first.second;
    int t=b.first.first+b.first.second;
    return s<t;
}

ll dp[10002];

int main(){
    int n;
    cin>>n;
    pair<pair<int,int>,int> b[n];
    for(int i=0;i<n;i++){
        int w,s,v;
        cin>>w>>s>>v;
        b[i]={{w,s},v};
    }
    sort(b,b+n,comp);
    for(int i=0;i<n;i++){
        int w=b[i].first.first;
        int s=b[i].first.second;
        ll v=b[i].second;
        for(int j=s;j>=0;j--){
            int to=min(10001,j+w);
            dp[to]=max(dp[to],dp[j]+v);
        }
    }
    ll ans=-1;
    for(int i=0;i<=10001;i++){
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
}