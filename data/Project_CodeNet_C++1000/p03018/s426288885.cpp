#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  string s;
  cin >> s;
  int n = s.size();
  vector<int> memo(n,0);
  ll ans = 0;
  for(int i=0; i<n-1; ++i){
    if(s[i] == 'B' && s[i+1] == 'C'){
      int x = i-1;
      int cnt = 0;
      while(x>=0 && s[x] == 'A'){
        ++cnt;
        --x;
      }
      ans += cnt;
      if(x>=0) ans += memo[x];
      memo[i+1] = cnt;
      if(x>=0) memo[i+1] += memo[x];
    }
  }
  cout << ans << endl;
}