#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll gcd(ll a,ll b){
  if(b%a==0) return a;
  else return gcd(b,a%b);
}

int main(){
  ll x,y;
  cin >> x >> y;
  if(x%y==0) cout << -1 << endl;
  else{
    if(gcd(x,y)!=2) cout << x*3 << endl;
    else cout << x*2 << endl;
  }
}