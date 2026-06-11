#include <bits/stdc++.h>
using namespace std;

int main(){
  string a,b;
  cin >> a >> b;
  bool ok=false;
  vector<char>ave(a.size());
  vector<char>bve(b.size());
  if(a.size()==b.size()){
  for(int i=0;i<a.size();i++){
    ave.at(i)=a.at(i);
  }
  for(int i=0;i<b.size();i++){
    bve.at(i)=b.at(i);
  }
  for(int i=0;i<a.size();i++){
    ok=true;
    int j=0;
    for(j=0;j<a.size()-i;j++){
      if(ave.at(j+i)!=bve.at(j)){
        ok=false;
        break;
      }
    }
    for(j=0;j<i;j++){
      if(ave.at(j)!=bve.at(a.size()+j-i)){
        ok=false;
        break;
      }
    }
    if(ok)
      break;
  }
  }
  cout << (ok?"Yes":"No") << endl;
  return 0;
}