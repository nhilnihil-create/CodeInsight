#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  
  double x[N];
  string s[N];
  for(int i=0;i<N;i++) {
    cin>>x[i]>>s[i];
  }
  double ans=0;
  
  for(int i=0;i<N;i++) {
    if(s[i]=="BTC"){
      x[i]=x[i]*380000.0;
      ans+=x[i];
    }
    else{
      ans+=x[i];
    }
  }
  cout<<fixed<<setprecision(5)<<ans<<endl;
  return 0;
}
