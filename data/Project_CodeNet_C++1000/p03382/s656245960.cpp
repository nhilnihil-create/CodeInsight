#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll a;
  cin>>a;
  vector<ll>vec(a);
  for(ll i=0;i<a;i++){
    cin>>vec.at(i);
  }
  sort(vec.begin(),vec.end());
  cout<<vec.at(a-1)<<' ';
  ll b=-1;
  ll c=vec.at(a-1);
  ll d=-100;
  ll e;
  for(ll i=0;i<a;i++){
    if(b==-1){
      if(vec.at(i)>c/2){
        b=i;
      }
    }
    vec.at(i)=min(vec.at(i),c-vec.at(i));
    if(vec.at(i)>d){
      d=vec.at(i);
      e=i;
    }
  }
  if(e>=b){
    d=c-vec.at(e);
  }
  cout<<d<<endl;
      
  return 0;
}
