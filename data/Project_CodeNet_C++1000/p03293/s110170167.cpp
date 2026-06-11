#include <bits/stdc++.h>
using namespace std;

int main(){
  string a,b;
  cin >> a >> b;
  bool ok=false;
  if(a.size()==b.size()){
  for(int i=0;i<a.size();i++){
    ok=true;
    for(int j=0;j<a.size();j++){
      if(a.at(j)!=b.at((j+i)%a.size())){
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