#include <bits/stdc++.h>
using namespace std;

int main(){
  string A;
  cin>>A;
  if(A.size()==2) cout<<A<<endl;
  else cout<<A.at(2)<<A.at(1)<<A.at(0)<<endl;
}