#include <bits/stdc++.h>
using namespace std;
using  ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
  string s;
  std::cin >> s;
  reverse(s.begin(),s.end());

  ll ans=0;
  int bcnt=0;
  for (int i = 0; i < s.size() ; i++) {
    if(s[i]=='B'){
      ans+=i-bcnt;
      bcnt++;
    }
  }
  std::cout << ans << '\n';



return 0;
}
