#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  string s;
  cin >> s;

  int count;
  int ans = 0;
  rep(i, s.size()){
    if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T'){
      count = 0;
      int j = 0;
      while(1){
        if (i + j >= s.size()) break;
        if (s[i+j] == 'A' || s[i+j] == 'C' || s[i+j] == 'G' || s[i+j] == 'T') count++;
        else break;
        if (ans < count) ans = count;
        ++j;
      }
    }
  }
  cout << ans << endl;
  return 0;
}