#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  string s;
 
  cin >> s;
  int ans=0;
  rep(i,s.size()){
    ans+=s.at(i)-'0';
  }
  if(ans!=1){
    cout<<ans<<endl;
  }
  else{
    cout<<10<<endl;
  }
}


