#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  double ans=0;
  cin>>n;
  vector<double>x(n);
  vector<string>u(n);
  for(int i=0;i<n;i++) cin>>x[i]>>u[i];
  for(int i=0;i<n;i++){
    if(u[i]=="JPY") ans+=x[i];
    else ans+=x[i]*380000.0;
  }
  cout<<setprecision(10)<<ans<<endl;
}
