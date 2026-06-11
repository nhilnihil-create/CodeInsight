#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  ll vec[n];
  ll ans=0;
  for(int i=0;i<n;i++){
    cin>>vec[i];
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<=n-i;j++){
      if(i+j>m){
        continue;
      }
      ll vecb[i+j]={};
      for(int k=0;k<i;k++){
        vecb[k]=vec[k];
      }
      for(int k=0;k<j;k++){
        vecb[i+k]=vec[n-k-1];
      }
      sort(vecb,vecb+i+j);
      for(int k=0;k<min(m-i-j,i+j);k++){
        if(vecb[k]<0){
          vecb[k]=0;
        }
      }
      ll sum=0;
      for(int k=0;k<i+j;k++){
        sum+=vecb[k];
      }
      ans=max(ans,sum);
    }
  }
  cout<<ans<<endl;
}