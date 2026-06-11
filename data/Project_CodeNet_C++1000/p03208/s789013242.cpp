#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,K;
  long long H=1000000001;
  cin>>N>>K;
  vector<long long>vec(N);
  for(int X=0;X<N;X++){
    cin>>vec.at(X);
  }
  sort(vec.begin(),vec.end());
  for(int X=0;K+X-1<N;X++){
    if(vec.at(K+X-1)-vec.at(X)<H){
      H=vec.at(K+X-1)-vec.at(X);
    }
  }
  cout<<H<<endl;
}