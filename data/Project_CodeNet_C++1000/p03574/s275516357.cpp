#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;

ll h , w ;
vector<string> S(55) ;

ll minesweeper(ll i , ll j ){
  ll count = 0 ;
  if(S[i][j] == '#' )return -1 ;
  if( i-1 >= 0 && j-1 >= 0 ) if(S[i-1][j-1] == '#')count++ ;
  if( j-1 >= 0 ) if(S[i][j-1] == '#')count++ ;
  if( i-1 >= 0 ) if(S[i-1][j] == '#')count++ ;
  if( i+1 <  h && j-1 >= 0 ) if(S[i+1][j-1] == '#')count++ ;
  if( i+1 <  h && j+1 < w ) if(S[i+1][j+1] == '#')count++ ;
  if( i+1 <  h ) if(S[i+1][j] == '#')count++ ;
  if( j+1 <  w ) if(S[i][j+1] == '#')count++ ;
  if( i-1 >= 0 && j+1 < w ) if(S[i-1][j+1] == '#')count++ ;
  return count ;
}
int main() {
	cin >> h >>w ;
    rep(i,h) cin >> S.at(i) ;
    rep(i,h){
      rep(j,w){
        if( minesweeper(i,j) == -1 ) cout << '#' ;
        else cout <<  minesweeper(i,j) ;
      }
      cout <<endl ;
    }
}