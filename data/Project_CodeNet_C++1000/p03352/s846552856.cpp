#include<bits/stdc++.h>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
  int N;
  cin>>N;
  int ans=0;
  if(N==1){
    ans=1;
  }
  for(int i=2;i<=10;i++){
    for(int j=1;j<N;j++){
      if(pow(j,i)<=N){
        int a=pow(j,i);
        ans=max(ans,a);
      }
    }
  }
  cout<<ans<<endl;
}
