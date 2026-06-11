#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<string,string> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n;
  string s;
  cin>>n>>s;
  P a[1<<n];
  rep(i,0,1<<n){
    string t,u;
    rep(j,0,n){
      if(i>>j & 1){
        t+=s[j];
      }
      else{
        u+=s[j];
      }
    }
    a[i]=P(t,u);
  }
  sort(a,a+(1<<n));
  
  ll ans=0;
  rep(i,0,1<<n){
    string t,u;
    rep(j,0,n){
      if(i>>j & 1){
        t+=s[2*n-1-j];
      }
      else{
        u+=s[2*n-1-j];
      }
    }
    ans+=upper_bound(a,a+(1<<n),P(t,u))-lower_bound(a,a+(1<<n),P(t,u));
  }
  cout<<ans<<endl;
}