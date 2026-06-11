#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  int K;
  cin >> K;
  ll a[N];
  ll R[N+1];
  R[0] = 0;
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    R[i+1] = R[i] + a[i]; 
  }
  vector<ll> lis;
  for (int i = 0; i <= N; i++) {
    for (int j = i+1; j <= N; j++) {
      lis.push_back(R[j] - R[i]);
    }
  }
  for (int bit = 50; bit >= 0; bit--) {
    vector<ll> lis2;
    
    for (int i = 0; i < (int)lis.size(); i++) {
      if ((1LL << bit) & lis[i]) {
        lis2.push_back(lis[i]);
      }
    }
    if ((int)lis2.size() >= K) {
      lis = lis2;
      
      ans += (1LL << bit);
    }
  }
  cout << ans << endl;
  return 0;
}