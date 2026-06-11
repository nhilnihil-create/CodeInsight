#include <bits/stdc++.h>
using namespace std;
int main() {
  int N,M;cin>>N>>M;long long K=0;
  vector<int>V(M);
  vector<int>I(M-1);
  for(int X=0;X<M;X++){
    cin>>V[X];
  }
  sort(V.begin(),V.end());
  for(int X=0;X<M-1;X++){
    I[X]=V[X+1]-V[X];
  }
  sort(I.begin(),I.end());
  for(int X=0;X<M-N;X++){
    K+=I[X];
  }
  cout<<K<<endl;
}