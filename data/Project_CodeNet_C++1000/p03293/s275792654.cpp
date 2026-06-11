#include <bits/stdc++.h>
using namespace std;

int main(){
  string a,b;
  cin >> a >> b;
  bool ok=false;
  vector<char>ave(a.size());
  vector<char>bve(b.size());
  for(int i=0;i<a.size();i++){
    ave.at(i)=a.at(i);
  }
  for(int i=0;i<b.size();i++){
    bve.at(i)=b.at(i);
  }
  for(int i=0;i<a.size();i++){
    char c=ave.at(ave.size()-1);
    ave.pop_back();
    reverse(ave.begin(),ave.end());
    ave.push_back(c);
    reverse(ave.begin(),ave.end());
    if(ave==bve){
      ok=true;
      break;
    }
  }
  cout << (ok?"Yes":"No") << endl;
  return 0;
}