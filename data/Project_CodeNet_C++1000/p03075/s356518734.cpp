#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main(){
  vector<int> v(5);
  rep(i,5)cin>>v.at(i);
  sort(v.begin(),v.end());
  int k; cin>>k;
  int d=v.at(4)-v.at(0);
  if(d>k)cout<<":(";
  else{cout<<"Yay!";}
}