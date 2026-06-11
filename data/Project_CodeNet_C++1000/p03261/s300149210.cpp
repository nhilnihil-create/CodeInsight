#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  int a;
  string s, t;
  set<string> x;
  bool shiritori = true;
  for(int i=0; i<n; i++) {
    //しりとり
    cin >> s;
    if(i != 0 && s[0] != t[t.size()-1]) shiritori = false;
    t = s;
    //被り
    a = x.size();
    x.insert(s);
    if(a == x.size()) shiritori = false;
  }
  if(shiritori) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}