#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  string a;
  cin>>a;
  ll b,c;
  b=0;
  c=0;
  for(ll i=0;i<a.size();i++){
    if(a.at(i)=='0'){
      b+=1;
    }
    else{
      c+=1;
    }
  }
  cout<<min(b,c)*2<<endl;
  return 0;
}
                             
    
