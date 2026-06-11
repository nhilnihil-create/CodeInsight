#include <bits/stdc++.h>
using namespace std;
 
int main() {
 int N,M;
  cin>>N;
  vector<int> money(N);
  vector<string> NString(N);
  for(int i=0;i<N;i++){
    cin>>NString.at(i);
  }
  cin>>M;
  vector<string> MString(M);
  for(int i=0;i<M;i++){
    cin>>MString.at(i);
  }
  
  int n1=0,n2=0;
  string re1,re2;
  for(int i=0;i<N;i++){
    re1=NString.at(i);
    for(int j=0;j<N;j++){
      re2=NString.at(j);
      if(re1==re2)
        money.at(i)++;
    }
    for(int j=0;j<M;j++){
      re2=MString.at(j);
      if(re1==re2)
        money.at(i)--;
    }
  }
  int most=0;
  for(int i=0;i<N;i++){
    if(most<money.at(i))
      most=money.at(i);
  }
  if(most<0)
    most=0;
  cout<<most<<endl;
  
}