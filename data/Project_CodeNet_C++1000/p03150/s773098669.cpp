#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define intll int long long
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main() {
  string s ; 
  cin >> s ; 
  string ans = "keyence" ;
  
  rep(i,7){
    string S = "";
    rep(j,s.size()){
      if(j<=i ||  i + s.size()-7 <j ) S = S + s.at(j) ;
    }
 
    if(S == ans ){
      cout <<"YES" ;
      return 0 ;
    }
  }
  
  cout << "NO" ;
  


}
