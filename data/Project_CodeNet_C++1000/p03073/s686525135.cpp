#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  string a;
  cin>>a;
  ll b=a.size();
  vector<char>vec(b);
  
  for(ll i=0;i<b;i++){
    vec.at(i)=a.at(i);
  }
  ll c=0;
  ll d=0;
  for(ll i=0;i<b;i++){
    if(i%2==vec.at(i)%2){
      c+=1;
    }
  }
  for(ll i=0;i<b;i++){
    if(i%2!=vec.at(i)%2){
      d+=1;
    }
  }
  cout<<min(c,d)<<endl;
}
   