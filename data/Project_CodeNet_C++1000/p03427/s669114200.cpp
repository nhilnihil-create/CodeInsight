#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll n;
  cin >> n;
  int c=1;//桁数
  ll k=1;//10^c
  
  ll x=n;
  
  while(x>9){
    x/=10;
    k*=10;
    c++;
  }
  
  x=n/k;//nの1番左の数
  
  if(n+1==(x+1)*k) cout << x+9*(c-1) << endl;
  else cout << x+9*c-10 << endl;
}