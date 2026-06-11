#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;cin>>n;
  string s[3];rep(i,3)cin>>s[i];
  
  char an[3];
  ll ans=0;
  rep(i,n) {
    rep(j,3)an[j]=s[j][i];
    sort(an, an+3);
    if (an[0]!=an[1] && an[1]!=an[2]) ans+=2;
    else if (an[0]!=an[1] || an[1]!=an[2]) ans++;
  }
  cout<<ans<<endl;
  
}
