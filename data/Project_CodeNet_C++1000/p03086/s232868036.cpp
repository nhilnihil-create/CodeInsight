#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  string S;
  cin >> S;

  string T = "ATGC";

  int ans = 0;

  int now = 0;
  rep(i, S.size()){
    bool isATGC = false;
    rep(j, T.size()){
      if (S[i] == T[j]) isATGC = true;
    }

    if (!isATGC) now = 0;
    else{
      now ++;
      ans = max(now, ans);
    }
  }
  cout << ans << endl;
}
