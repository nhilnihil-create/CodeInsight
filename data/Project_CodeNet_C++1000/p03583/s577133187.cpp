#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll n;
  cin >> n;
  
  for(ll i = 1; i <= 3500; i++){
    for(ll j = 1; j <= 3500; j++){
      if(4 * i * j - n * i - n * j != 0){
        if((n * i * j) % (4 * i * j - n * i - n * j) == 0){
          ll k = (n * i * j) / (4 * i * j - n * i - n * j);
          if(k > 0){
            cout << i << " " << j << " " << k << '\n';
            return 0;
          }
        }
      }
    }
  }
}