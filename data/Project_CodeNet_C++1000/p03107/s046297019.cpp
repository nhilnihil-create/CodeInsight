#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define endl "\n"
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

void solve(){
  string s;
  cin >> s;
  ll zero = 0, one = 0;
  for(char x: s){
    if(x == '1')
      ++one;
  }
  zero = s.size() - one;
  cout << 2 * min(zero, one) << endl;
}

int main(){
  fastio;
  solve();
  return 0;
}
