#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (ll i = m; i < (n); i++)

using ll = long long;
using pii = pair<int, int>;
using Vi = vector<int>;

int main() {
  string s;
  cin >> s;
  int c = 0;
  rep(i, 3){
    if(s[i]-'0' == 1){
      c++;
    }
  }
  cout << c << endl;
  
}