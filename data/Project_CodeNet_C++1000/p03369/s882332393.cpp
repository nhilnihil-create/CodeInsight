#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main() {
  string s; cin >> s;
  int ans = 700;
  rep(i,3){
    if(s[i] == 'o')ans+= 100;
  }
  cout << ans;
}