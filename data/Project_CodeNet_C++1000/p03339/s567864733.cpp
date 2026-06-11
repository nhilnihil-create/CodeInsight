#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }


int main() {
  
  int N; 
  cin >> N;
  string S;
  cin >> S;

  vector<int> left(N + 1);
  vector<int> right(N + 1);
  int n = 0;
  for(int i = 1; i <= N; i++) {
    if(S[i - 1] == 'W') { n++; left[i] = n; } 
    else { left[i] = n; }
  }
  n = 0;
  for(int i = N - 1; i >= 0; i--) {
    if(S[i] == 'E') { n++; right[i] = n; }
    else { right[i] = n; }
  }
  int ans = 400000;
  for(int i = 0; i < N; i++) {
    if(ans > left[i] + right[i + 1]) ans = left[i] + right[i + 1];
  }
  
  cout << ans;
  return 0;
}