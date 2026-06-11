#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,K;
  cin>>N>>K;
  vector<int>vec(N);
  for(int X=0;X<N;X++){
    cin>>vec.at(X);
  }
  if((N-1)%(K-1)==0){
    cout<<(N-1)/(K-1)<<endl;
  }
  else{
    cout<<(N-1)/(K-1)+1<<endl;
  }
}