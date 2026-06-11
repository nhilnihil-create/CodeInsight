#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  string a;
  cin>>a;
  string d=a+a;
  string b;
  cin>>b;
  ll c=a.size();
  for(ll i=0;i<c;i++){
    for(ll j=0;j<c;j++){
      if(d.at(i+j)!=b.at(j)){
        break;
      }
      if(j==c-1){
        cout<<"Yes"<<endl;
        return 0;
      }
    }
  }
  cout<<"No"<<endl;
        
    
  
  return 0;
}
