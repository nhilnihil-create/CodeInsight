#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M;cin>>N>>M;
  vector<int>V(N+1);
  for(int X=0;X<M;X++){
    int L,R;cin>>L>>R;
    V[L-1]++;V[R]--;
  }
  long long rui=0;
  int S=0;
  for(int X=0;X<N;X++){
    rui+=V[X];
    if(rui==M){
      S++;
    }
  }
  cout<<S<<endl;
}