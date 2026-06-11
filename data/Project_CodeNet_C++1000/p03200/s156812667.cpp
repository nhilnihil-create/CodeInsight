#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
int main(){
  string s;cin>>s;
  ll stsi=s.size(),ans=0,b=0;
  ll a[stsi];fill(a,a+stsi,0);
  for(ll i=0;i<stsi;i++){
    if(s.at(i)=='W'){a[i]++;}
  }
  for(ll i=0;i<stsi;i++){
    if(a[i]==1){ans+=i-b;b++;}
  }
  cout << ans<<endl;
}