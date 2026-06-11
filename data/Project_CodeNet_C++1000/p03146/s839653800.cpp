#include <bits/stdc++.h>
using namespace std;
int main(){
   int s;
  cin>>s;
  vector<int> x(1000000);
  int ans=1;
  int ansh=0;
  x[0]=s;
  for(int i=1;i<1000000;i++){
    if(s%2==0){
      s/=2;
    }
    else{
      s=3*s+1;
    }
    x[i]=s;
    for(int j=0;j<i-1;j++){
      if(s==x[j]){
        ansh++;
        break;
      }
    }
    ans++;
    if(ansh==1){
      break;
    }
  }
  cout<<ans<<endl;
}