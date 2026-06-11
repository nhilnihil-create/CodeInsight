#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll n, k;
  cin >> n >> k;
  
  if(k % 2 == 1){
    ll a = 0;
    for(int i = 1; i <= n; i++){
      if(i % k == 0) a++;
    }
    cout << a * a * a << '\n';
  }
  else{
    ll a = 0, b = 0;
    for(int i = 1; i <= n; i++){
      if(i % k == 0) a++;
      else if(i % k == k / 2) b++;
    }
    cout << a * a * a + b * b * b << '\n';
  }
}