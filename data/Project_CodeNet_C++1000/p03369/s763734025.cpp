#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int p;
  p = 700;
  string s;
  cin >> s;
  rep(i,3){
    if(s[i] == 'o'){
      p += 100;
    }
  }
  cout << p;
  return 0;
}