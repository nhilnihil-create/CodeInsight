#include <bits/stdc++.h>
using namespace std;
#define ll long long 

void chmax(ll& a, ll b) {
  if (a < b) a = b;
}

int main() {
  ll N, M;
  cin >> N >> M;
  ll ans = 1;
  
  for (int i = 1; i * i <= M; i++) {
    if (M % i == 0 &&  i * N <= M) {
      chmax(ans, i);
    
      if (M/i * N <= M) {
        chmax(ans, M/i);
      }
    }
  }
  
  cout << ans << endl;
}