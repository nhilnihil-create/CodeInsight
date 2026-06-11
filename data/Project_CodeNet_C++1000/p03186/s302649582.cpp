#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
  ll a,b,c; cin >> a >>b >> c;
  ll min_bc = min(b,c);
  ll d,ans;
  
  if(b>=c){
    d = b - min_bc ;
    if(d <= a){
      ans = 2*min_bc + d;
    }else{
      ans = 2*min_bc + a +1;
    }
  }else{
    d = c - min_bc;
    if(d <= a){
      ans = 2*min_bc + d;
    }else{
      ans = 2*min_bc + a +1;
    }
  }
  cout << ans << endl;
}
    
  