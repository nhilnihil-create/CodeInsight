#include<bits/stdc++.h>
using namespace std;
int main() {
  int n,i;
  double x,ans=0.0;
  string u;
  cin>>n;
  for(i=0;i<n;i++){
    cin>>x>>u;
    if(u=="JPY") ans+=x;
    else if(u=="BTC") ans+=x*380000.0;
  }
  cout<<fixed<<setprecision(10)<<ans<<endl;
}