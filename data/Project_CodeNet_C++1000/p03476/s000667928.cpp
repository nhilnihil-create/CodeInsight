#include <bits/stdc++.h>
using namespace std;

int main(){
  int P[100010];
  int K[100010];
  int T[100010];
  for(int i=0;i<100009;i++){
    P[i]=1;
    K[i]=0;
    T[i]=0;
  }

  for(int i=2;i<1005;i++){
    for(int j=2;j<100010/i+1;j++){
      P[i*j]=0;
    }
  }
  P[1]=1;
  P[2]=1; 
  
  for(int i=0;i<100010;i++){
    if(P[i]==1 && P[(i+1)/2]==1){
      K[i]=1;
    }
  }
  
  int temp=0;
  T[0]=0;
  T[1]=0;
  T[2]=0;  
  for(int i=3;i<100010;i++){
    T[i]=temp+K[i];
    temp=T[i];
  }

    
  int Q;
  cin>>Q;
  int l,r;
  for(int i=0;i<Q;i++){
    cin>>l>>r;
    cout<<T[r]-T[l-1]<<endl;
  }
      
  /*for(int i=1;i<20;i++){
    cout<<i<<" "<<T[i]<<endl;
  }*/
  
  //cout<<T[1]<<" "<<T[53]<<endl;
  
  return 0;
}
