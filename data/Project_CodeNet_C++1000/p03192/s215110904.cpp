#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;

int main(){
  string s;cin >> s;
  int len = s.length();
  int ans = 0;
  rep(i,len)if(s[i] == '2')ans += 1;
  cout << ans << endl;
  return 0;
}