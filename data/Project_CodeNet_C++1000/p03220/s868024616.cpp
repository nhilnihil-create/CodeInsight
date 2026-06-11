#include<bits/stdc++.h>
using namespace std;

int main( void )
{
  int N, T, A;
  cin >> N >> T >> A;
  vector<int> H( N );
  double max = 100000;
  int maxi = 0;
  
  for( int i = 0; i < N; i++ ) {
    cin >> H.at( i );
    if( abs( (double)( T - H.at( i ) * 0.006 ) - (double)A ) < max ) {
      //cout << "TEST" << endl;
      max = abs( ( T - H.at( i ) * 0.006 ) - A );
      maxi = i;
    }
  }
  cout << maxi + 1 << endl;
}