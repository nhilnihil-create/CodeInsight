#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  string s;
  cin >> s;
  int cnt=0;
  int64_t ans=0;
  rep(i,s.length()){
    if(s[s.length()-i-1]=='B'){
      ans+=cnt;
    }
    else cnt++;
  }
  cout << ans << endl;

}