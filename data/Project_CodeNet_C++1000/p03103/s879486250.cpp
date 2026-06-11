#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M;
  cin>>N>>M;
  vector<pair<long long,long long>>AB(N);
  for(int X=0;X<N;X++){
    int A,B;
    cin>>A>>B;
    AB[X]=make_pair(A,B);
  }
  sort(AB.begin(),AB.end());
  long long K=0;
  long long F=0;
  for(int X=0;X<N;X++){
    long long C,D;
    tie(C,D)=AB[X];
    if(F+D<=M){
      K+=C*D;
      F+=D;
    }
    else{
      K+=C*(M-F);
      F+=M-F;
      break;
    }
  }
  cout<<K<<endl;
}