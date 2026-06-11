#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  ll a;
  cin>>a;
  ll b=0;
  double c=0;
  for(ll i=0;i<a;i++){
    double d;
    string e;
    cin>>d>>e;
    if(e=="JPY"){
      b+=d;
    }
    else{
      c+=d;
    }
  }
  cout<<fixed<<setprecision(8);
  cout<<c*380000+b<<endl;
  
      
    
  
  return 0;
}
                             
    
