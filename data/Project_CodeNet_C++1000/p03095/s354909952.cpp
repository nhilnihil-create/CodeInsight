#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF=1000000007;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  map<char,int> mp;
  rep(i,n) {
    mp[s[i]]++;
  }
  ll ans=1;
  for(auto p: mp) {
    ans*=(p.second+1);
    ans%=INF;
  }
  if(ans==0) ans=INF-1;
  else ans--;
  cout << ans << endl;
}
