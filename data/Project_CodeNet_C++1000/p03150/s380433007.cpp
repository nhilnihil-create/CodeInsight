#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int main(){
  string s;
  std::cin >> s;

  string key="keyence";


  if(s.substr(0,7)=="keyence" || s.substr(s.size()-7,7)=="keyence"){std::cout << "YES" << '\n';return 0;}

  int f=0;
  rep(i,7){
    if(s[f]!=key[f])break;
    f++;
  }

  bool ok=true;

  for (int i = s.size()-7+f; i < s.size(); i++) {
    if(s[i]!=key[f])ok=false;
    f++;
  }

  if(ok)std::cout << "YES" << '\n';
  else std::cout << "NO" << '\n';

  return 0;
}
