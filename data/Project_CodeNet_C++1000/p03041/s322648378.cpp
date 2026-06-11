#include <iostream>
 
using namespace std;
int main() {
  int N; cin>>N;
  int K; cin>>K;
  char S[N];
    for(int x=0; x<N ; x++){
      char a; cin>>a;
      S[x]= a;
    }
  S[K-1]+=32;
  for(int b=0; b<N ;b++){
    cout<< S[b];
  }
  return 0;
}