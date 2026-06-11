#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  for(int i=1; i<n-1; i++) {
    int count = 0;
    vector<char> c1(i);
    vector<char> c2(n-i);
    for(int j=0; j<i; j++) {
      c1.at(j) = s.at(j);
    }
    for(int j=0; j<n-i; j++) {
      c2.at(j) = s.at(i+j);
    }
    sort(c1.begin(), c1.end());
    sort(c2.begin(), c2.end());
    for(int j=0; j<i; j++) {
      if(j<i-1) {
        if(c1.at(j) == c1.at(j+1)) {
          continue;
        }
      }
      for(int k=0; k<n-i; k++) {
        if(k<n-i-1) {
          if(c2.at(k) == c2.at(k+1)) {
            continue;
          }
        }
        if(c1.at(j) == c2.at(k)) {
          count++;
        }
      }
    }
    ans = max(ans, count);
  }
  cout << ans << endl;
}