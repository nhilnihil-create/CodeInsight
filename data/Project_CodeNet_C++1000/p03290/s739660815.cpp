#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int d;
  ll g;
  cin>>d>>g;
  ll vec[d][2];
  for(int i=0;i<d;i++){
    cin>>vec[i][0]>>vec[i][1];
  }
  int vecb[d];
  int ans=10000,pr=0,sc=0;
  for(int bit=0;bit<(1<<d);bit++){
    for(int i=0;i<d;i++){
      if(bit&(1<<i)){
        vecb[i]=1;
      }
      else{
        vecb[i]=0;
      }
    }
    pr=0,sc=0;
    for(int i=0;i<d;i++){
      if(vecb[i]==1){
        pr+=vec[i][0];
        sc+=vec[i][0]*(i+1)*100+vec[i][1];
      }
    }
    if(sc>=g){
      ans=min(pr,ans);
      continue;
    }
    for(int i=d-1;i>=0;i--){
      if(vecb[i]==0){
        pr+=min((g-sc+i*100+99)/(i*100+100),vec[i][0]-1);
        sc+=min((g-sc+i*100+99)/(i*100+100),vec[i][0]-1)*(i+1)*100;
      }
      if(sc>=g){
        ans=min(pr,ans);
        break;
      }
    }
  }
  cout<<ans<<endl;
}