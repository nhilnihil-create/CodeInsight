#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  int n = 0;
  string s;
  cin >> s;
  for(auto x : s) {
    if(x == '+') ++n;
    else --n;
  }
  
  cout << n << endl;
  
  return 0;
}
