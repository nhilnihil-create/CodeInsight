#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main() {
  ll N = 0,ans = 0;
  cin >> N;
  vector<ll>A(N);
  rep(i,N){
    cin >> A[i];
  }
  ll cum[N+1];
  cum[0] = 0;
  map<ll, ll> mp;
  mp[0]++;
  rep(i,N){
    cum[i + 1] = cum[i] + A[i];
    mp[cum[i+1]]++;
  }
  for (auto p : mp){
    ans += (p.second * (p.second -1)) /2;
  }
  cout << ans;
}