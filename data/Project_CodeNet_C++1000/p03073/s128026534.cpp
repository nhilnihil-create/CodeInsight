#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

string S;

int main(){
  cin >> S;
  int ans = 100010;

  int cnt = 0;
  rep(i, S.size()){
    if (i % 2 == 0){
      if (S[i] == '0') cnt ++;
    }
    if (i % 2 == 1){
      if (S[i] == '1') cnt ++;
    }
  }
  ans = min(ans, cnt);

  cnt = 0;
  rep(i, S.size()){
    if (i % 2 == 1){
      if (S[i] == '0') cnt ++;
    }
    if (i % 2 == 0){
      if (S[i] == '1') cnt ++;
    }
  }
  ans = min(ans, cnt);
  cout << ans << endl;
}
