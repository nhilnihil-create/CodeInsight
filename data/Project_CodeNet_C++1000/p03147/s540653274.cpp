#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;cin>>N;
  vector<int>V(N+1);
  for(int X=1;X<=N;X++){
    cin>>V[X];
  }
  int I=0;
  for(int X=1;X<=N;X++){
    if(V[X]>V[X-1]){
      I+=V[X]-V[X-1];
    }
  }
  cout<<I<<endl;
}
