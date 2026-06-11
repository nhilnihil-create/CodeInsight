#include <bits/stdc++.h>
using namespace std;
int main(){
  double n,t,a;
  cin>>n>>t>>a;
  int ans;
  double mini=1e8;
  for(int i=0;i<n;i++){
    double h;
    cin>>h;
    double temp=t-h*0.006;
    if(abs(a-temp)<abs(a-mini)){
      mini=temp;
      ans=i;
    }
  }
  cout<<ans+1<<endl;
}