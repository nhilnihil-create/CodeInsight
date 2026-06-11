#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string line;
  cin >> line;
  int n = line.size();
  vector<int> s(n);
  rep(i,0,n) {
    s[i] = stoi(line.substr(i,1));
  }
  int a = 0,b = 0;
  int c = 0,d = 1;
  rep(i,0,n) {
    if (s[i] != c) a++;
    if (s[i] != d) b++;
    c ^= 1; d ^= 1;
  }
  cout << min(a,b) << endl;
  return 0;
}
