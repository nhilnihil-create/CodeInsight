#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,min_sumAB=100000000000000;
  cin >> N;
  for(int i=0;i<N-1;i++){
    int A=i+1,B=N-i-1;
    int sumA=0,sumB=0;
    while(A>0){
      sumA+=A%10;
      A/=10;
    }
    while(B>0){
      sumB+=B%10;
      B/=10;
    }
    int sumAB=sumA+sumB;
    min_sumAB=min(min_sumAB,sumAB);
  }
  cout << min_sumAB << endl;
}
    
      