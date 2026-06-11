#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  string a;
  cin>>a;
  int b;
  for(int i=0;i<a.size();i++){
    if(a.at(i)!='1'){
      b=i+1;
      break;
    }
  }
  ll k;
  cin>>k;
  if(k<b){
    cout<<1<<endl;
  }
  else{
    cout<<a.at(b-1)<<endl;
  }
  
  return 0;
}
