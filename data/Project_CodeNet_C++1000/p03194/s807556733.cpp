#include <string>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

int main(){
  ll N,P;
  vector<ll> a{1},b{1};//soinsuu
  cin>>N>>P;
  if(N==1){
    cout<<P<<endl;
    return 0;
  }
  ll maxa= P/(N*2);
  if(sqrt(P)<maxa)maxa=sqrt(P);
  for(ll i=2;i<=maxa;++i){
    if(i>P)break;
    if(P%i==0){
      if(a.back()!=i){
      	a.push_back(i);
        b.push_back(1);
      }else{
        b.back()++;
      }
      P/=i;
      i--;
    }
  }
  ll ans=1;
  for(int i=1;i<a.size();++i){
    ll tmp = pow(a[i],(b[i]/N));
    //cout<<"tmp"<<tmp<<endl;
    ans*=tmp;
  }
  /*for(auto num:a){
  	cout<<num<<endl;
  }
  cout<<"--"<<endl;
  for(auto num:b){
  	cout<<num<<endl;
  }*/
  
  cout<<ans<<endl;
  return 0;
}