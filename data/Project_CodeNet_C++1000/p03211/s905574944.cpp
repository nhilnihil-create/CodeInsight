#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
  
  string s;
  cin >> s;
  
  int n = s.size() - 2;
  int m = 999;
  REP(i,n) {
    int x = (s[i] - '0') * 100 + (s[i+1] - '0') * 10 + (s[i+2] - '0');
    m = min(m,abs(753-x));
  }

  cout << m << endl;

}