#include <bits/stdc++.h>
using namespace std;
using  ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
  string s;
  std::cin >> s;
  int cnt=0;
  int ans=0;
  rep(i,s.size()){
    if(s[i]=='A' || s[i]== 'C' || s[i]=='G' || s[i]=='T'){
      cnt++;
    }
    else {ans=max(ans,cnt);cnt=0;}
  }
  ans=max(ans,cnt);
  std::cout << ans << '\n';
  return 0;
}
