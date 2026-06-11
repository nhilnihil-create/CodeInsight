#include <bits/stdc++.h>
using namespace std;
using  ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

const int MAX=INT_MAX;

int main(){
  int n;
  int ans=0;
  string s;
  std::cin >> n >> s;

  for (int i = 1; i < s.size(); i++) {
    bool a[2][26];
    rep(j,26){
      a[0][j]=false;
      a[1][j]=false;
    }

    for (int j = 0; j < s.size(); j++) {
      if(j>=i)a[0][s[j]-'a']=true;
      else a[1][s[j]-'a']=true;
    }
    int now=0;
    rep(j,26)if(a[0][j] &&  a[1][j])now++;

    ans=max(ans,now);

  }

  std::cout << ans << '\n';
  return 0;
}
