#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  int sum = 0;
  vector<int> v(s.size());
  for(int i=0; i<s.size(); i++) {
    string t;
    t = s[i];
    v[i] = stoi(t);
    sum += v[i];
  }
  if(stoi(s)%sum==0) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}