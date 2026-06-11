#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long K,A,B;
  long long N=1;
  cin>>K>>A>>B;
  for(long long X=0;X<K;X++){
    if(A+2<B){
      if(N<A){
        N++;
      }
      else{
        if(X+1<K){
          N+=B-A;
          X++;
        }
        else{
          N++;
        }
      }
    }
    else{
      N++;
    }
  }
  cout<<N<<endl;
}