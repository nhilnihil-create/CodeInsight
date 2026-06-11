#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int s;
  map<int, int> mp;
  cin >> s;
  int ans = 0;
  while (1) {
    mp[s]++;
    ans++;
    if(mp[s] == 2) break;
    if(s % 2){
      s = 3 * s + 1;
    }
    else  {
      s /= 2;
    }
  }
  cout << ans << endl;
  return 0;
}