#include <bits/stdc++.h>
using namespace std;
int main(){
  double n,m,d,ans; cin>>n>>m>>d;
  if(d==0) ans=(m-1)/n;
  else ans=(n-d)*2*(m-1)/n/n;
  cout<<setprecision(9)<<ans<<endl;
}