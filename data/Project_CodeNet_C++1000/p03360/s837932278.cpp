#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<int> z(3);
  int x,i;
  cin>>z.at(0)>>z.at(1)>>z.at(2)>>x;
  sort(z.begin(),z.end());
  for(i=0;i<x;i++) z.at(2)*=2;
  cout<<z.at(0)+z.at(1)+z.at(2)<<endl;
}