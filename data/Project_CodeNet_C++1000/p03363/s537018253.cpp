#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define int long long
//#define _GLIBCXX_DEBUG

signed main() {
  int N; cin >> N;
  vector<int> A(N);
  rep(i, N) {
    int a; cin >> a;
    if(i == 0) A[i] = a;
    else A[i] = A[i-1]+a;
  }
  
  int ans = 0;
  
  unordered_map<int,int> map;
  map[0]++;
  rep(i, N) map[A[i]]++;
  for(auto p : map) {
    if(p.second > 1) ans += (p.second*(p.second-1))/2;
  }
  cout << ans << endl;
}
