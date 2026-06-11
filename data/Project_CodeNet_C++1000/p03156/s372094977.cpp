#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, A, B;
  cin >> N >> A >> B;
  int P=0, Q=0, R=0;
  int C;
  for(int i=0; i<N; i++){
    cin >> C;
    if(C<=A){
      P++;
    }
    else if(C<=B){
      Q++;
    }
    else{
      R++;
    }
  }
  cout << min(P, min(Q, R)) << endl;
}