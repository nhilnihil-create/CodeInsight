#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<long double> x(n);
  vector<string> u(n);
  for(int i=0;i<n;i++)cin>>x.at(i)>>u.at(i);
  long double ans=0;
  for(int i=0;i<n;i++){
    if(u.at(i)=="BTC"){
      x.at(i)*=380000;
      ans+=x.at(i);
    }else{
      ans+=x.at(i);
    }
  }
  cout<<fixed<<setprecision(10)<<ans<<endl;
  return 0;
}