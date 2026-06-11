#include <bits/stdc++.h>
#include <set>
#define rep(i,n) for (int i=0; i < (n); ++i)
using namespace std;


int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans=0;
  int cnt=0;

  rep(i,n) {
    if (s[i] == 'R') ans++;
    else cnt++; 
  }
  if (ans > cnt) cout << "Yes";
  else cout << "No";
  cout << endl;
  return 0;  

}
