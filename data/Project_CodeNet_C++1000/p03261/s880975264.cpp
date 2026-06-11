#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll a;
  cin>>a;
  vector<string>vec(a);
  string b;
  cin>>b;
  char c=b.at(b.size()-1);
  vec.at(0)=b;
  
  
  for(ll i=1;i<a;i++){
    string d;
    cin>>d;
    vec.at(i)=d;
    if(c!=d.at(0)){
      cout<<"No"<<endl;
      return 0;
    }
    c=d.at(d.size()-1);
  }
  sort(vec.begin(),vec.end());
  for(ll i=0;i<a-1;i++){
    if(vec.at(i)==vec.at(i+1)){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
  
    
  return 0;
}

