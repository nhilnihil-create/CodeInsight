#include<bits/stdc++.h>
using namespace std;
int main(){
  int z,x;
  cin>>z;
  vector<int> y(z);
  for(x=0;x<z;x++) cin>>y.at(x);
  sort(y.begin(),y.end());
  cout<<y.at(z-1)-y.at(0)<<endl;
}