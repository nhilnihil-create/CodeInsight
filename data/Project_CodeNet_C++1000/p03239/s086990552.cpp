#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,t;
  cin>>n>>t;
  vector<int> c(n);
  vector<int> x(n);
  for(int i=0;i<n;i++){
    cin>>c[i]>>x[i];
  }
  int ans=1001;
  for(int i=0;i<n;i++){
    if(x[i]<=t){
      if(ans>c[i]){
        ans=c[i];
      }
    }
  }
  if(ans==1001){
    cout<<"TLE"<<endl;
  }
  else{
    cout<<ans<<endl;
  }
}