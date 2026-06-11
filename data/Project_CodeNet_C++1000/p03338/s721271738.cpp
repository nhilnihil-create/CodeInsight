#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
#define all(a) a.begin(), a.end() 
using namespace std;

int count(string x, string y) {
  map<char, bool> mpx;
  map<char, bool> mpy;
  for(char c : x) mpx[c] = true;
  for(char c : y) mpy[c] = true;
  
  int ans = 0;
  rep(i, 26) {
    char c = i + 'a';
    if(mpx[c] && mpy[c]) ++ans;
  }
  
  return ans;
}

int main() {
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  for(int i = 1; i < n; ++i) {
    string x = s.substr(0, i);
    string y = s.substr(i, n-i);
    
    ans = max(ans, count(x, y));
  }
  
  cout << ans << endl;
  return 0;
}
