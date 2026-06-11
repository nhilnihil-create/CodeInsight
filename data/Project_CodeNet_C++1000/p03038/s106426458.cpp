#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ll N, M;
  cin >> N >> M;
  
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  
  vector<pair<ll, ll>> change_vec;
  
  for (int i = 0; i < M; i++) {
    ll B, C;
    cin >> B >> C;
    
    change_vec.push_back({C, B});
    
  }
  
  sort(change_vec.begin(), change_vec.end());

  ll index = 0;
  ll m = change_vec.size();
  

  for (ll i = m-1; i >= 0; i--) {
    pair<ll, ll> p = change_vec[i];
    
    
    for (ll j = 0; j < p.second; j++) {
    
      if (A[index] < p.first) {
        A[index] = p.first;
        index++;
      } else {
        break;
      }
      
    }
    
  }

  ll ans = 0;
  for (int i = 0; i < N; i++) {
    ans += A[i];
  }
  cout << ans << endl;
  
}