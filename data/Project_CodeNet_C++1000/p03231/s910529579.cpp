#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll n,m,l,g,i;
  string s,t;
  cin >> n >> m >> s >> t;
  g=__gcd(n,m);
  l=n*m/g;
  for(i=0;i<g;i++){
    if(s.at(i*n/g)!=t.at(i*m/g)){
      cout << -1 << endl;
      return 0;
    }
  }
  
  cout << l << endl;
}