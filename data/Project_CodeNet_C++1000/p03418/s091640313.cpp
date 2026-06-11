#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for(ll i=0; i<N; ++i)

ll max(ll a, ll b) {return a < b ? b : a; }

int main() {
  int N, K;
  cin >> N >> K;
  
  ll sum = 0;
  
  for(int b = K + 1; b <= N; ++b) {
    
    sum += (b - K) * (N / b);
    // if(K != 0) {
      int nmod = (N - b * (N / b));
      sum += max(nmod - K + (K!=0), 0);
    // }
  }
  
  cout << sum << endl;
  
  return 0;
}