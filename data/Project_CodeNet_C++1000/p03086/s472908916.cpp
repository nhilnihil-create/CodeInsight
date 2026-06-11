#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  vector<char> a(s.size());
  for(int i=0; i<s.size(); i++) a[i] = s[i];
  
  int max = 0;
  int count = 0;
  for(int i=0; i<s.size(); i++) {
    if(a[i]=='A' || a[i] == 'T' || a[i] == 'C' || a[i] == 'G') 
      if(i != s.size()-1) count++;
      else {
        count++;
        if(max < count) max = count;
      }
    else if(max < count) {
      max = count;
      count = 0;
    } 
    else count = 0;
  }
  cout << max << endl;
  return 0;
}