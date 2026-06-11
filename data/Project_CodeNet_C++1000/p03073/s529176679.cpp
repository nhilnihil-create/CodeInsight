#include <bits/stdc++.h>
#define rep(i, e, n) for (int i = e; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const ll inf=1000000000007;

int main() {
  string s;
  cin >> s;
  ll ans =0;
//  cout << s.size() << endl;
  ll cnt=0;
  rep(i,0,s.size()){
    if(i%2==0 && s[i]=='0') cnt++;    
    if(i%2==1 && s[i]=='1') cnt++;
  }
  ans = cnt;
  cnt=0;
//  cout << ans << endl;
  rep(i,0,s.size()){
    if(i%2==0 && s[i]=='1') cnt++;    
    if(i%2==1 && s[i]=='0') cnt++;
  }
  ans = min(ans,cnt);

  cout << ans << endl;
  return 0;
}