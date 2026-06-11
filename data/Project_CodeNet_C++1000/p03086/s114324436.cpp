#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;



int main() {
  string S; cin >> S;
  string T = "ACGT";
  int m = S.size();
  int s[m];
  int ans = 0;
  int cnt = 0;

  rep(i,m) s[i] = 0;

  rep(i,m){
    rep(j,4){
      if(S[i] == T[j]) s[i] = 1;
    }
  }


  rep(i,m){
    if(s[i] == 1) {
      cnt++;
    }
    else {
      ans = max(ans,cnt);
      cnt = 0;
    }
  }
  ans = max(ans,cnt);
  cout << ans << endl;


  return 0;
}






