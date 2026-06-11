#include <bits/stdc++.h> 
using namespace std; 
int main() { 
  int N, K; 
  cin >> N >> K; 
  int ans = 1;
  int i = 0;
  while (i<N) {
    if (ans+K>=ans*2) {
      ans*=2;
      i++;
    }
    else {
      ans+=K;
      i++;
    }
  }
  cout << ans << endl;
}
