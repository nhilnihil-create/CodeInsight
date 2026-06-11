#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> P;
int main(){
    int n,D[51];
    cin>>n;
    D[0]=0;
    rep(i,n) cin>>D[i+1];
    sort(D,D+n+1);
    int ans=D[1]-D[0];
    rep(i,(n+1)/2) D[2*i+1]=24-D[2*i+1];
    sort(D,D+n+1);
    rep(i,n) ans=min(ans,D[i+1]-D[i]);
    cout<<ans;
}