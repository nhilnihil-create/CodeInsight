#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  int N;
  
  cin >> N;
  
  vector<int> a(N+2, 0);
  for (int i = 0; i < N; i++) cin >> a[i];
  
  vector<ll> s(N+2, 0);
  map<ll, ll> nums;
  
  nums[0]++;
  for (int i = 0; i < N; i++) {
    s[i+1] = s[i] + a[i];
    nums[s[i+1]]++;
  }

  ll res = 0;
  for (auto it : nums) {
    ll num = it.second;
    res += num * (num -1) / 2;    
  }
  cout << res << endl;
  
  
  
  
    

}