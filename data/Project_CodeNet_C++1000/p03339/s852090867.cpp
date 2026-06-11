#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;string S;cin>>N>>S;int WW=0;
  vector<int>V(N+1),A(N);
  for(int X=0;X<N;X++){
    if(S[X]=='W'){
      V[X+1]++;V[N]--;
    }
    else{
      V[0]++;V[X]--;
    }
  }
  int R=0;
  for(int X=0;X<N;X++){
    R+=V[X];
    A[X]=R;
  }
  sort(A.begin(),A.end());
  cout<<A[0]<<endl;
}
