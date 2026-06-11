#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  int U=0;
  cin>>N;
  vector<int>V(N);
  vector<int>C(N);
  for(int X=0;X<N;X++){
    cin>>V[X];
  }
  for(int X=0;X<N;X++){
    cin>>C[X];
  }
  for(int X=0;X<N;X++){
    if(V[X]>C[X]){
      U+=V[X]-C[X];
    }
  }
  cout<<U<<endl;
}
