#include<bits/stdc++.h>
using namespace std;

int main( void )
{
  int H, W;
  cin >> H >> W;
  vector<string> S( H );
 
  for( int i = 0; i < H; i++ )
    cin >> S.at( i );

  int dx[ 8 ] = { 1, 0, -1, 0, 1, -1, -1, 1 };
  int dy[ 8 ] = { 0, 1, 0, -1, 1, 1, -1, -1 };

  for( int i = 0; i < H; i++ ) {
    for( int j = 0; j < W; j++ ) {
      if( S.at( i ).at( j ) == '.' ) {
	int num = 0;
	for( int d = 0; d < 8; d++ ) {
	  int ni = i + dx[ d ];
	  int nj = j + dy[ d ];
	  if( ni < 0 || ni >= H )
	    continue;
	  if( nj < 0 || nj >= W )
	    continue;
	  if( S.at( ni ).at( nj ) == '#' )
	    num++;
	}
	S.at( i ).at( j ) = num + '0';
      }
    }
  }

  for( int i = 0; i < H; i++ )
    cout << S.at( i ) << endl;
}