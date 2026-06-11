#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

using namespace std;

int main(){
  string s;
  cin >> s;

  //入力が1種類の場合
  bool allFlag = true;
  rep(i,s.size()-1){
    if(s[i] != s[i+1]) allFlag = false;
  }

  if(allFlag){
    cout << s.size() << endl;
    return 0;
  }
  //その他の処理
  int ans = 10000000;
  rep(i,s.size()-1){
    if(s[i+1] != s[i]) ans = min(ans,max(i+1,(int)s.size()-i-1));
  }
  cout << ans << endl;
  return 0;
}
