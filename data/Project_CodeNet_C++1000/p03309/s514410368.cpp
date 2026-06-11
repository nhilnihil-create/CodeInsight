//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF= 1e9+5;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>>vvi;

int main(){
  int n;
  cin>>n;
  vector<ll>a(n);
  rep(i,n)cin>>a[i];
  rep(i,n)a[i]-=i+1;
  sort(a.begin(),a.end());
  ll med,mednext;
  if(n%2==1)med=a[n/2];
  else med=(a[n/2]+a[n/2-1])/2,mednext=(a[n/2]+a[n/2-1])/2+1;
  ll ans=0;
  rep(i,n){
    ans+=abs(a[i]-med);
  }
  if(n%2==0){
    ll nextans=0;
    rep(i,n){
      nextans+=abs(a[i]-mednext);
    }
    ans=min(nextans,ans);
  }
      
  cout<<ans<<endl;
}
    