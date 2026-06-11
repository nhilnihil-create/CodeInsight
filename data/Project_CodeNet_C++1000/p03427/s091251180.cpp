#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  string  s;
  cin >> s;
  int n=s.size();
  int m = 0;
  rep(i,n-1) {
      if(s[i+1]=='9') m+=(s[i]-'0');
      else {
        m+=((s[i]-'0')-1);
        for (int j = i+1; j < n; j++) s[j] = '9';
      }
  }
  m += s.at(n-1)-'0';
  cout << m << endl;
}