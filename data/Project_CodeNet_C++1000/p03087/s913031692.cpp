#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,Q;
  string S;
  cin>>N>>Q>>S;
  unordered_set<int> A;
  vector<int> B(0);
  for(int i=0;i<N-1;i++){
    if(S.at(i)=='A' && S.at(i+1)=='C')
      A.insert(i);
  }
  int j=0;
  B.push_back(0);
  for(int i=0;i<N;i++){
    if(A.count(i))
      j++;
    B.push_back(j);
  }
  for(int i=0;i<Q;i++){
    int l,r;
    cin>>l>>r;
    cout<<B.at(r-1)-B.at(l-1)<<endl;
  }
}