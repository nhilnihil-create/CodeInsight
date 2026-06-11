#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,Y;
  cin >> N >> Y;
  
  int cnt =0;
  for(int i=0;i<=N;i++){
    if(Y>10000*N){
      cout << -1 << " " << -1 << " " << -1 <<endl;
      break;
      }
    if(cnt==1){
      break;
    }
    for(int j=0;j<=N-i;j++){
      if(Y==10000*i+5000*j+1000*(N-i-j)){
        cout << i << " " << j << " " << N-i-j <<endl;
        cnt++;
        break;
      }
      if(N==i){
        cout << -1 << " " << -1 << " " << -1 <<endl;
      }
      if(Y!=10000*i+5000*j+1000*(N-i-j)){
        continue;
      }
      
    }
  }
}