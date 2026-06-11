#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int>x(n);
  for(int i=0;i<n;i++){
  cin>>x[i];
  }
  sort(x.begin(),x.end());
  int ans=0;
  vector<int>y(n);
  for(int j=0;j<n;j++){
  if(x[j]>n){
  ans++;
  }
  else{
  y[x[j]-1]++;
  }
  }
  for(int k=0;k<n;k++){
  if(y[k]>=k+1){
  ans+=y[k]-(k+1);
  }
  else if(y[k]>0){
  ans+=y[k];
  }
  }
  cout<<ans<<endl;
}