#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long N;
  bool K=false;
  cin>>N;
  vector<int>T(N+1);
  vector<int>X(N+1);
  vector<int>Y(N+1);
  for(int P=0;P<N;P++){
    cin>>T[P+1]>>X[P+1]>>Y[P+1];
    if(abs(X[P+1]-X[P])+abs(Y[P+1]-Y[P])>T[P+1]-T[P]||(abs(X[P+1]-X[P])+abs(Y[P+1]-Y[P]))%2!=(T[P+1]-T[P])%2){
      K=true;
    }
  }
  if(K==false){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}