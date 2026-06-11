#include <bits/stdc++.h>
using namespace std;
  
int main(){
  int D,G;
  cin >>D>>G;
  int P[D];
  int C[D];
  int K[D];
  for(int i=0;i<D;i++){
    cin>>P[i]>>C[i];
  }
  int ans=0;
  int temp=0;
  int minans=10000;

  for(int i=0;i<(1 << D);i++){
    ans=0;
    temp=0;
    fill(K,K+D,1);
    
    for(int j=0;j<D;j++){
      if(i & (1<<j)){
        K[j]=0;
        ans+=P[j];
        temp+=P[j]*(j+1)*100+C[j];
      }
    }
    //cout<<i<<" "<<temp<<"#1#"<<ans<<endl;
    //足りないときは点数の高い未回答問題を中途半端に解く
    if(temp<G){
      for(int k=D-1;k>=0;k--){
        if(K[k]==1){
          int hampa=(G-temp)/((k+1)*100);
          if(hampa>P[k]){
            break;
          }
          //cout<<"####"<<hampa<<"#"<<k<<"#"<<K[k]<<endl;
          if((G-temp)%((k+1)*100) != 0){
            hampa++;      
          }
          ans+=hampa;
          temp+=hampa*(k+1)*100;         
          break;
        }
      }
    }
    //cout<<i<<" "<<temp<<"#2#"<<ans<<endl;
    if(temp>=G){
      minans=min(minans,ans);
    }
  }

  cout<<minans<<endl;
  return 0;
}
