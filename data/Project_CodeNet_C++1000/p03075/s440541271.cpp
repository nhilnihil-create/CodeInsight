#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  vector<ll>vec(5);
  for(ll i=0;i<5;i++){
    cin>>vec.at(i);
  }
  ll a;
  cin>>a;
  if(vec.at(4)-vec.at(0)>a){
    cout<<":("<<endl;
  }
  else{
    cout<<"Yay!"<<endl;
  }


  return 0;
  
}
