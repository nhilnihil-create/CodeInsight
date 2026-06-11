#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
  int n,b = 0,r = 0;
  string s;
  cin >> n >> s;
  rep(i,n){
    if(s[i] == 'B') b++;
    else r++;
  }
  if(b < r) cout << "Yes" << endl;
  else cout << "No" << endl;
}