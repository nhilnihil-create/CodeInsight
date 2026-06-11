#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;cin>>N;
  int X=N/4+1;
  bool can=false;
  for(int i=0;i<=X;i++){
    int j=0;
    while(true){
      if(4*i+7*j==N){
        can=true;
        break;
      }
      if(4*i+7*j>N) break;
      j++;
    }
    if(can) break;
  }
  cout<<(can?"Yes":"No")<<endl;
}