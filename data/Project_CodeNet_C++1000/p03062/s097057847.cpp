#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  int minus_cnt=0;
  int d=INT_MAX;
  rep(i,n){
    cin>>a[i];
    d=min(abs(d),abs(a[i]));
    if(a[i]<0) minus_cnt++;
  }
  ll ans=0;
  rep(i,n) ans+=abs(a[i]); 
  if(minus_cnt%2==0) cout<<ans<<endl;
  else cout<<ans-2*(ll)d<<endl;
}
