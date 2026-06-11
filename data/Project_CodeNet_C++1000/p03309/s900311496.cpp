#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  int N;
  cin >> N;
  vector<ll> a(N);
  
  for (int i = 0; i < N; i++) {
    ll x;
    cin >> x;
    
    a[i] = x - (i+1);
  }
  
  
  sort(a.begin(), a.end());
  
  ll b = a[N/2];
  
  ll ans = 0;
  
  for (int i = 0; i < N; i++) {
    ans += abs(a[i] - b);
  }
  
  cout << ans << endl;
}