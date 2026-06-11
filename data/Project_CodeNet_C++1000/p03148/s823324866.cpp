#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
int main(){
    ll n,k,t,d;
    cin>>n>>k;
    vector<pair<ll,ll>> A,B,C;
    int var[200001]={0};
    rep(i,n) cin>>t>>d,A.push_back(make_pair(d,t));
    sort(A.begin(),A.end(),greater<pair<ll,ll>>());
    rep(i,k) B.push_back(A[i]),var[A[i].second]++;
    rep(i,n-k) C.push_back(A[i+k]);
    reverse(B.begin(),B.end());
    ll c=0,ans=0,sum=0,x=0;
    rep(i,k) sum+=B[i].first;
    rep(i,n) if(var[i+1]) x++;
    ans=sum+x*x;
    rep(i,k){
        if(var[B[i].second]>1){
            while(c<n-k&&var[C[c].second]!=0) c++;
            if(c==n-k) break;
            var[B[i].second]--;
            sum-=B[i].first;
            B[i].first=C[c].first;
            B[i].second=C[c].second;
            var[B[i].second]++;
            sum+=B[i].first;
            x++;
        }
        ans=max(ans,sum+x*x);
    }
    cout<<ans;
}