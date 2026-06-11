#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int ans = 0;
  rep(i,3){
    char s;
    cin >> s;
    if(s == '1'){
      ans++;
    }
  }
  cout << ans;
  return 0;
}