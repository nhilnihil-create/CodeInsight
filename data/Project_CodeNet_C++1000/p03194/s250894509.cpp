#include <bits/stdc++.h>
using namespace std;
 
map< int64_t, int > prime_factor(int64_t n) {
  map< int64_t, int > ret;
  for(int64_t i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

int main() {
  int64_t N,P;
  cin >> N >>P;
  
  map<int64_t, int> factrial;
  
  factrial = prime_factor(P);

  int64_t out=1;
  for(auto p : factrial ){
    if(p.second >= N){
        out*=pow(p.first,p.second/N);
    }
  }

  cout <<out<< endl;
}