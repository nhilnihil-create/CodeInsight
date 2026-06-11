#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,K;cin>>N>>K;
  vector<long long>T(N);
  for(int X=0;X<N;X++){
    cin>>T[X];
  }
  long long U=1000000000;
  sort(T.begin(),T.end());
  for(int X=0;X<=N-K;X++){
    if(T[X+K-1]-T[X]<U){
      U=T[X+K-1]-T[X];
    }
  }
  cout<<U<<endl;
}