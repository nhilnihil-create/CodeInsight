#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<int> dish(5);
  for(int i=0;i<5;i++){
    cin>>dish[i];
  }
  vector<int> d(5);
  for(int i=0;i<5;i++){
    d[i]=dish[i]%10;
  }
  sort(d.begin(),d.end());
  int x;
  for(int i=0;i<5;i++){
    if(d[i]==0){
      ;
    }
    else{
      x=d[i];
      break;
    }
  }
  int ans=0;
  int z=0;
  for(int i=0;i<5;i++){
    if(dish[i]%10==0){
      ans+=dish[i];
    }
    else if(dish[i]%10==x&&z==0){
      z++;
      ans+=dish[i];
    }
    else{
      ans+=dish[i]+(10-dish[i]%10);
    }
  }
  cout<<ans<<endl;
}