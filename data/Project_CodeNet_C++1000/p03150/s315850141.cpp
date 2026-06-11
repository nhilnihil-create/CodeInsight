#include <bits/stdc++.h>
using namespace std ;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;

int main(){
  string s ;
  cin >> s ;
  string t = "keyence" ;
  rep(i,s.size()){
    rep(j,s.size()){
      string u = s ;
    //  cout<<u.erase(i,j)<<" "<<endl;
      if( u.erase(i,j) == t ){
        cout << "YES" << endl;
        return 0 ; }
    }
  }

  cout << "NO" << endl;

  return 0;
}

