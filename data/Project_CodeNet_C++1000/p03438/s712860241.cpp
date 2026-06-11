#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int main(){
    ll n,A[200001],B[200001],suma=0,sumb=0;
    cin>>n;
    rep(i,n) cin>>A[i],suma+=A[i];
    rep(i,n) cin>>B[i],sumb+=B[i];
    ll a=0,b=0;
    rep(i,n){
        if(A[i]<B[i]) a+=(B[i]-A[i]+1)/2;
        else b+=A[i]-B[i];
    }
    if(max(a,b)<=sumb-suma) cout<<"Yes";
    else cout<<"No";
}
