#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  string s; cin >> s;
  vector<bool> a(s.size());
  rep(i,s.size()){
    if(s[i]=='0') a[i] = false;
    else a[i] = true;
  }

  int ans = 0;
  for(int i = 0;i<s.size();i++){
    if(i+1==s.size()) continue;
    if(a[i+1]==a[i]){
      a[i+1] = !a[i];
      ans++;
    }
  }
  
  cout << ans << endl;
    
  return 0;
}
