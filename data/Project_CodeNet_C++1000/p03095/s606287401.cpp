#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr ll mod = 1e9+7;
int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<ll> cnt(26,0);
  for (int i = 0; i < n; i++) {
    cnt[s[i] - 'a']++;
  }
  ll res = 1;

  for (int i = 0; i < 26; i++) {
    (res *= cnt[i] + 1) %= mod;
  }
  cout << (res + mod - 1) % mod << endl;
  return 0;
} 
