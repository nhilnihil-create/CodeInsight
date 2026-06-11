#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
ll n,k,A[200001],B[200001],ans=0;
vector<ll> C;
int search(){
    ll b;
    for(int i=60;i>=0;i--){
        ll c=pow(2,i);
        ll a=0;
        rep(j,C.size()) if(C[j]>=c&&(c^C[j])==C[j]-c) a++;
        if(a>=k){ans+=pow(2,i);b=pow(2,i);break;}
        if(i==0) return 0;
    }
    vector<ll> D;
    rep(i,C.size()) if(C[i]>=b&&(b^C[i])==C[i]-b) D.push_back(C[i]-b);
    C=D;
    search();
}
int main(){
    cin>>n>>k;
    rep(i,n) cin>>A[i];
    B[0]=0;
    rep(i,n) B[i+1]=A[i]+B[i];
    rep(i,n+1)rep(j,n+1) if(i<j) C.push_back(B[j]-B[i]);
    sort(C.begin(),C.end());
    search();
    cout<<ans;
}