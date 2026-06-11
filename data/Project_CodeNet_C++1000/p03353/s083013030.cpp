#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;
 
int main() {
  string s ;
  cin >> s ;
  int m  ;
  cin >> m ;
  vector<char> T ;
  vector<string> U ;
  int n = s.size() ;
  map<char,int> mp ;
  map<string,int> mp2 ;
  rep(i,n) mp[s[i]]++ ;
  int ans = 0 ;
  for(auto p : mp ){
    int q = p.second ;
    if( q > 0 ) {
      T.push_back(p.first) ;
      ans++ ;
    }
  }
  //rep(i,ans) cout << T[i] << endl ;
  ans = 0 ;
  for(int i = 0 ; i < n ; i++ ){
    for(int j = 1 ; j < 6 ; j++ ){
      //cout << s.substr(0,3) << endl;
      mp2[s.substr(i,j)]++ ;
    }
  }
  for(auto p : mp2 ){
    int q = p.second ;
    if( q > 0 ) {
      U.push_back(p.first) ;
      ans++ ;
    }
  }
  cout << U[m-1] << endl ;
}