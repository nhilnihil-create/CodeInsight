#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m,b;
  cin >> n;
  map<int,int>tmt;
  for(int i=0;i<n;i++){
    cin >> b;
    tmt[b]++;
  }
  cin >> m;
  map<int,int>hty;
  for(int i=0;i<m;i++){
    cin >> b;
    hty[b]++;
  }
  bool ans=true;
  for(auto x:hty){
    if(tmt[x.first]<x.second)
      ans=false;
  }
  cout << (ans?"YES":"NO") << endl;
  return 0;
}