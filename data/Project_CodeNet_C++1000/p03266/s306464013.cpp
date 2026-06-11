#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
  
  int n,k; cin>>n>>k;
  if(k%2==0){
    ll x = n/k;
    ll y = n/(k/2);
    y -= x;
    cout << x*x*x+y*y*y<<endl;
  }
  else{
    ll x = n/k;
    cout << x*x*x<<endl;
  }
  
  
  
}