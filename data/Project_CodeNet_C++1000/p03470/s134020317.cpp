#include<bits/stdc++.h>
using namespace std;

int main( void )
{
  int N;
  int befor = 0;
  int count = 0;
  
  cin >> N;

  vector<int> d( N );
  
  for( int i = 0; i < N; i++ )
    cin >> d.at( i );

  sort( d.begin(), d.end(), greater<int>() );

  for( int i = 0; i < N; i++ ) {
    if( d.at( i ) != befor ) {
      count++;
    }
    befor = d.at( i );
  }
  if( count == 0 )
    count++;
  
  cout << count << endl;
}