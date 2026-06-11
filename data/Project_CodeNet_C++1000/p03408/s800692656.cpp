
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int ans = 0;
  string s;
  int n;
  cin >> n;
  map<string, int> mp;
  string a[n];
  rep(i, n){
    cin >> a[i];
    mp[a[i]]++;
  }
  int x;
  cin >> x;
  rep(i, x){
    cin >> s;
    mp[s]--;
  }
  rep(i, n){
    ans = max(ans, mp[a[i]]);
  }
  cout << ans << endl;
  return 0;
}