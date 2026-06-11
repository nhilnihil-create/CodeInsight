#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  string s, t = "";
  cin >> s;
  int ans = 999;
  rep(i, s.size() - 2){
    t += s[i];
    t += s[i + 1];
    t += s[i + 2];
    ans = min(ans, abs(753 - stoi(t)));
    t = "";
  }
  cout << ans << endl;
  return 0;
}