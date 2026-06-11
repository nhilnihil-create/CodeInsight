#include<bits/stdc++.h>
using namespace std;

int main( void )
{
  int N, X;
  cin >> N >> X;
  vector<int> m( N );
  int count = 0;
  int min = INT_MAX;
  
  for( int i = 0; i < N; i++ ) {
    cin >> m.at( i );
    X -= m.at( i );
    count++;
    if( min > m.at( i ) )
      min = m.at( i );
  }

  while( X >= min ) {
    count++;
    X -= min;
  }

  cout << count << endl;
 
}