#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
int main(){
    int n,m,A[10],dp[200000],B[11]={0,2,5,5,4,5,6,3,7,6};
    cin>>n>>m;
    rep(i,m) cin>>A[i];
    rep(i,n+1) dp[i]=-1;
    dp[0]=0;
    rep(i,n)rep(j,m) if(dp[i]!=-1) dp[i+B[A[j]]]=max(dp[i]+1,dp[i+B[A[j]]]);
    vector<int> C;
    int b=n;
    while(b>0){
        int a=0,c=0;
        rep(i,m) if(dp[b-B[A[i]]]>=a&&b-B[A[i]]>=0){
            if(dp[b-B[A[i]]]>a) c=A[i];
            else c=max(c,A[i]);
            a=dp[b-B[A[i]]];
        }
        b-=B[c];
        C.push_back(c);
    }
    sort(C.begin(),C.end(),greater<int>());
    for(auto i:C) cout<<i;
}