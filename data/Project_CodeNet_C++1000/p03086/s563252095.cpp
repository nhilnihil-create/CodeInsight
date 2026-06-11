#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  string s;
  cin >> s;
  int n =sz(s);

  string t = "ACGT";

  int cnt = 0;
  int ans = 0;
  rep(i,n){
    bool flag = 0;
    rep(j,4){
      if(s[i] == t[j]) flag = 1;
    }
    if(flag){
      cnt++;
      ans = max(ans,cnt);
    }else{
      cnt = 0;
    }
  }
  cout << ans << endl;
  
}
