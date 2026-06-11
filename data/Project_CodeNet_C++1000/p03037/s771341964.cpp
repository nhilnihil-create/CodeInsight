#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;cin>>N>>M;
  vector<int> L(M),R(M);
  for(int i=0;i<M;i++) cin>>L.at(i)>>R.at(i);
//  vector<bool> A(N,true);
  sort(L.begin(),L.end());
  sort(R.begin(),R.end());
  reverse(L.begin(),L.end());
  if(L.at(0)<=R.at(0)) cout<<R.at(0)-L.at(0)+1<<endl;
  else cout<<0<<endl;
}
  
  
