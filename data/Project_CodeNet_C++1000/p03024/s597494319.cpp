#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  int k = s.length();
  int cnt = 0;
  for (char c: s) {
    if (c == 'o') {
      ++cnt;
    }
  }
  if (cnt + 15 - k >= 8) {
    cout<<"YES"<<endl;
  } else {
    cout<<"NO"<<endl;
  }
}