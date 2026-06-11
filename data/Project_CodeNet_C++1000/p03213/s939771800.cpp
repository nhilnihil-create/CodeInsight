#include <bits/stdc++.h>
using namespace std;

map<int, int> primeFactor(int n){
  map<int, int> ret;
  for (int i = 2; i*i <= n; i++){
    while(n%i==0) {
      ret[i]++;
      n /= i;
    }
  }
  if (n !=1 ) ret[n]++;
  return ret;
}
map<int, int> factorialPrimes(int n){  
  if (n==1) {
    map<int, int> blank;
    return blank;
  }
  map<int, int> ret = factorialPrimes(n-1);
  map<int, int> primes = primeFactor(n);
  for (auto prime: primes){
    ret[prime.first] += prime.second;
  }
  return ret;
}

int main(){
  int N;
  cin >> N;
  
  map<int, int> primeFacts = factorialPrimes(N);
  
  int ans = 0;
  for (auto pf: primeFacts) {
    if (pf.second>=74) ans++;
    
    if (pf.second>=24) {
      for (auto pf2: primeFacts) {
        if (pf2.first == pf.first) continue;
        
        if (pf2.second>=2) ans++;
      }
    }

    if (pf.second>=14) {
      for (auto pf2: primeFacts) {
        if (pf2.first==pf.first) continue;
        
        if (pf2.second>=4) ans++;
      }
    }

    if (pf.second>=4) {
      for (auto pf2: primeFacts) {
        if (pf2.first<=pf.first) continue;
        
        if (pf2.second>=4) {
          for (auto pf3: primeFacts) {
            if(pf3.first==pf2.first) continue;
            if(pf3.first==pf.first) continue;
            
            if (pf3.second>=2) ans++;
          }
        }
      }
    }
      
  }
  
  cout << ans << endl;
  
}