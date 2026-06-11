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
  map<int,int> m;
  rep(i, N) {
    int a; cin >> a;
    m[a]++;
  }
  
  int ans = 0;
  for(auto p : m) {
    if(p.second < p.first) ans += p.second;
    if(p.second > p.first) ans += p.second-p.first;
  }
  cout << ans << endl;

}