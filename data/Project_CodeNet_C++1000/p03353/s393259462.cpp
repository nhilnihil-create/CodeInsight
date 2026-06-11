#include <bits/stdc++.h>
using namespace std;


int main(){
  
  string s;
  cin>>s;
  
  int k;
  cin>>k;
  
  set<string> myset;
  
  for (int i=0;i<int(s.size());i++){
    for (int j=1;j<=min(5,int(s.size())-i);j++){
      string tmp;
      tmp=s.substr(i,j);
      myset.insert(tmp);
    }
  }
  
  vector<string> vec;
  
  for (auto x:myset){
    vec.push_back(x);
  }
  
  sort(vec.begin(),vec.end());
  
  cout<<vec.at(k-1)<<endl;
         
  

  
  
}