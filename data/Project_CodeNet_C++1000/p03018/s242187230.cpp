#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
  string s; cin >> s;
  int n = s.size();

  int acnt = 0;
  ll ans = 0;
  rep(i, n - 1){
    //cout << s[i] << " ";
    if(s[i] == 'A'){
      acnt++;
    }
    else{
      if(s[i] == 'B' && s[i + 1] == 'C'){
        ans += acnt;
        i++;
      }
      else{
        acnt = 0;
      }
    }
    //cout << acnt << endl;
  }
  //cout << s.size() << endl;
  //cout << n << endl;
  cout << ans << endl;
  return 0;
}
