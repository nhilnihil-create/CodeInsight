/*
  the solution from editorial
*/
#pragma optimize("O3")
#include<bits/stdc++.h>
using namespace std;

long long t, a, b, c, d;
int main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> t;
  while(t--){
    cin >> a >> b >> c >> d;
    if(a < b || d < b) cout << "No\n";
    else if(c >= b) cout << "Yes\n";
    else{
      if(a %  __gcd(b, d) > c - b + __gcd(b, d)) cout << "No\n";
      else cout << "Yes\n";
    }
  }
  return 0;
}
