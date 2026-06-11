#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  vector<char>vec(3);
  for(ll i=0;i<3;i++){
    cin>>vec.at(i);
    if(vec.at(i)=='1'){
      vec.at(i)='9';
    }
    else{
      vec.at(i)='1';
    }
  }
  for(ll i=0;i<3;i++){
    cout<<vec.at(i);
  }
  cout<<endl;
  return 0;
}
  
  
    
    
  
