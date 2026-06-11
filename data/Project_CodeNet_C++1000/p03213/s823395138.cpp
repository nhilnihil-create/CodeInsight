#include <bits/stdc++.h>
using namespace std;

array<int,101> factoring(int x){
  array<int,101> ret{};

  for(int i = 2; sqrt(x) >= i; i++){
    while(x % i == 0){
      ret[i]++;
      x/=i;
    }
  }
  if(x > 1) ret[x]++;
  return ret;
}

int main(){
  array<int,101> fac{};
  int n;
  cin >> n;
  for(int i = 1; n >= i; i++){
    auto buf = factoring(i);
    for(int j = 0; 101 > j; j++)
      fac[j] += buf[j];
  }
  int ans = 0;

  for(int i = 1; n >= i; i++){
    if(fac[i] < 2) continue;
  for(int j = 1; n >= j; j++){
    if(fac[j] < 4 ||i==j) continue;
  for(int k = j+1; n >= k; k++){
    if(fac[k] < 4 ||i==k) continue;
    ans++;
  }
  }
  }
  
  for(int i = 1; n >= i; i++){
    if(fac[i] < 4) continue;
  for(int j = 1; n >= j; j++){
    if(fac[j] < 14 ||i==j) continue;
    ans++;
  }
  }
  
  for(int i = 1; n >= i; i++){
    if(fac[i] < 2) continue;
  for(int j = 1; n >= j; j++){
    if(fac[j] < 24 ||i==j) continue;
    ans++;
  }
  }

  for(int i = 1; n >= i; i++){
    if(fac[i] < 74) continue;
    ans++;
  }
  cout << ans << endl;
}