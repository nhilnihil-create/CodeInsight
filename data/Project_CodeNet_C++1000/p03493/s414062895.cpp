#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ll long long
using namespace std;


int main() {
  string s;
  cin >> s;
  int count = 0;
  rep (i, 3) {
    if (s.at(i) == '1') {
      count++;
    }
  }
  cout << count << endl;
  
}