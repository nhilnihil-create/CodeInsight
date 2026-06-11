#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> s;

int solve();

int main(){
  cin >> n;
  s.resize(n);
  for(int i = 0;i < n;++i)
    cin >> s[i];
  cout << solve() << endl;
  return 0;
}

int solve(){
  int ans = 0;
  for(int a = 0;a < n;++a){
    bool ch = 1;
    for(int i = 0;i < n;++i)
      for(int j = 0;j < n;++j)
        if(s[(a+i)%n][j] != s[(a+j)%n][i])
          ch = 0;
    ans += ch;
  }
  return ans * n;
}