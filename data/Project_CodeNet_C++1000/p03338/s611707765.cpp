#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  string s;
  cin >> n >> s;
  
  string x, y;
  int count = 0;
  int ans = 0;
  for(int i=0; i<n-1; i++) {
    x = s.substr(0,i+1);
    y = s.substr(i+1);
    sort(x.begin(), x.end());
    for(int j=0; j<x.size(); j++) {
      if(j==0 || x[j]!=x[j-1]) {
        for(int k=0; k<y.size(); k++) {
          if(x[j]==y[k]) {
            count++;
            break;
          }
        }
      }
    }
    if(count>ans) ans = count;
    count = 0;
  }
  cout << ans << endl;
}