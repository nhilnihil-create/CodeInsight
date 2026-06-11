#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  int N; cin >> N;
  string S; cin >> S;
  
  int ans = 1;
  map<char,int> map;

  rep(i, N) {
    map[S[i]]++;
  }
  
  for(auto p : map) {
    ans *= p.second+1;
    ans %= 1000000007;
  }
  
  cout << ans-1 << endl;
}