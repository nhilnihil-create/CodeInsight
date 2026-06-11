#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  cin>>N>>K;
  vector<int> A(0),B={0};
  for(int i=0;i<N;i++){
    int j;
    cin>>j;
    if(j<0)
      A.push_back(0-j);
    else if(j==0)
      K--;
    else
      B.push_back(j);
  }
  if(K==0){
    cout<<0<<endl;
    return 0;
  }
  A.push_back(0);
  reverse(A.begin(),A.end());
  int j=1000000000;
  for(int i=0;i<=K;i++){
    if(A.size()>i && B.size()>K-i)
      j=min(j,A.at(i)+B.at(K-i)+min(A.at(i),B.at(K-i)));
  }
  cout<<j<<endl;
}