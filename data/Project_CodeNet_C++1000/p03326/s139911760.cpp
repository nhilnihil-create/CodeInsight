#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n,m;
  cin>>n>>m;
  ll x[n];
  ll y[n];
  ll z[n];
  rep(i,0,n) cin>>x[i]>>y[i]>>z[i];
  ll ans=0;
  rep(i,0,8){
    int p=i%2;
    int q=i/2%2;
    int r=i/4%2;
    p=2*p-1;
    q=2*q-1;
    r=2*r-1;
    ll a[n];
    rep(j,0,n){
      a[j]=x[j]*p+y[j]*q+z[j]*r;
    }
    sort(a,a+n);
    reverse(a,a+n);
    ll cur=0;
    rep(j,0,m){
      cur+=a[j];
    }
    ans=max(ans,cur);
  }
  cout<<ans<<endl;
}