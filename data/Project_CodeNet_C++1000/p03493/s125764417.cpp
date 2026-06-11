#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  string s;
  cin >> s;
  int ans = 0;
  for(char x : s) if(x == '1') ++ans;
  cout << ans << endl;
  
  return 0;
}
