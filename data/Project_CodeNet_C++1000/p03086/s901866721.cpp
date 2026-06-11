#include <bits/stdc++.h>
#define rep(i, e, n) for (int i = e; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const ll inf=1000000000007;

int main() {
  string s;
  cin >> s;
  int n=s.size();
//  cout << n << endl;
  int ans=0;
  int cnt=0;

  rep(i,0,n){
    if(s[i]=='A' || s[i]=='C' || s[i]=='G' || s[i]=='T') cnt++;
    else {
      ans=max(ans,cnt);
      cnt=0;
    }
  }
  ans=max(ans,cnt);
  cout << ans << endl;

  return 0;
}