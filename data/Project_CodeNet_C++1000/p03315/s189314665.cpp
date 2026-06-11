#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  string a;
  cin>>a;
  ll b=0;
  ll c=0;
  for(ll i=0;i<4;i++){
    if(a.at(i)=='+'){
      b+=1;
    }
    else{
      c+=1;
    }
  }
  cout<<b-c<<endl;
    
  return 0;
}
