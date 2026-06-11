#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  string s;
  cin >> s;
  map<char, int> mp;
  
  for(char x : s) ++mp[x];
  
  for(auto x : mp) {
    if(x.second != 1) {
      cout << "No" << endl;
      return 0;
    }
  }
  
  cout << "Yes" << endl;
    
  
  return 0;
}
