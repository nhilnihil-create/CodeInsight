#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  ll n,a,b,c,d,e;
  cin>>n>>a>>b>>c>>d>>e;
  ll mi=min(min(a,b),min(c,min(d,e)));
  ll ans;
  if(n%mi==0)ans = n/mi+5-1;
  else ans = n/mi+5;
  cout<<ans<<endl;
}
