#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t N, A, B, C, D, E;
  cin >> N >> A >> B >> C >> D >> E;
  int64_t m=min(A, min(B, min(C, min(D, E))));
  int64_t Ans=0;
  if(N%m==0){
    Ans=N/m;
  }
  else{
    Ans=N/m+1;
  }
  cout << Ans+4 << endl;
}