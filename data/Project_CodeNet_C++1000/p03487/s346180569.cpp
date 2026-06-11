#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N; cin >> N; int64_t sum = 0;
  
  map<int64_t, int64_t> memo;
  
  for (int i = 0; i < N; i++) {
    
    int64_t a; cin >> a;
    
    memo[a]++;
    
  }
  
  for (auto x : memo) {
    
    int64_t key = x.first, value = x.second;
    
    if (value < key) sum += value;
    
    else sum += value - key;
    
  }
  
  cout << sum << endl;
  
}