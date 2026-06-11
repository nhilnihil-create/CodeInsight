#include <bits/stdc++.h>
using namespace std;

long long product[20][2];

void fact(long long P){
  if(P==1){
    product[0][0]=1;
    product[0][1]=1;
  }else{
    int now=0;
    long long div=2;
    while(div*div<=P){
      while(P%div==0){
        product[now][1]++;
        P/=div;
      }
      if(product[now][1]>0){
        product[now][0]=div;
        now++;
      }
      if(div==2) div++;
      else div+=2;
    }
  }
}

int main(){
  for(int i=0; i<20; i++){
    product[i][0]=0;
    product[i][1]=0;
  }
  long long N,P; cin >> N >> P;
  if(N==1||P==1){
    cout << P << endl;
    return 0;
  }
  fact(P);
  long long res=1;
  for(int i=0; i<20; i++){
    if(product[i][0]>0&&product[i][1]>=N){
      for(int j=0; j<product[i][1]/N; j++){
        res*=product[i][0];
      }
    }
  }
  cout << res << endl;
}