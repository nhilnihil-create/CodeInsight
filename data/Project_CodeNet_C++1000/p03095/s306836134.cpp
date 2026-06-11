#include <bits/stdc++.h>
using namespace std;

#define ll long long 

const ll MOD = 1000000007;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  
  vector<ll> count(30, 0);
  
  for (int i = 0; i < N; i++) {
    count[S[i] - 'a']++;
  }
  
  ll ans = 1;
  for (int i = 0; i < 26; i++) {
    ans *= count[i]+1;
    ans %= MOD;
  }
  
  ans--;
  
  cout << ans << endl;
}