#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,A,B;
  int wa=0;
  int syu=0;
  cin>>N>>A>>B;
  for (int X=1;X<=N;X++){
    wa=0;
    int M=X;
    for (int Y=1;Y<=X;Y*=10){
      if(Y==1){
        wa+=M%10;
      }
      else{
        M/=10;
        wa+=M%10;
      }
    }
    if (wa>=A && wa<=B){
      syu+=X;
    }
  }
  cout<<syu<<endl;
}