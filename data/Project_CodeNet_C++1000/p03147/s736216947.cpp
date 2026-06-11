#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  int vec[n+2];
  vec[0]=0,vec[n+1]=0;
  for(int i=1;i<=n;i++){
    cin>>vec[i];
  }
  int ans=0;
  for(int t=0;t<5000;t++){
    for(int i=0;i<n+2;i++){
      if(vec[i]!=0){
        while(vec[i]!=0){
          vec[i]--;
          i++;
        }
        ans++;
      }
    }
  }
  cout<<ans<<endl;
}