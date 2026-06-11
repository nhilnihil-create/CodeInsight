#include<bits/stdc++.h>
using namespace std;

int main( void )
{
  string s, t;
  cin >> s >> t;
  int size;
  bool large = false;
  int count = 0;
  sort( s.begin(), s.end() );
  sort( t.begin(), t.end() ,greater<int>() );

  if( s.size() > t.size() )
    size = t.size();
  else
    size = s.size();
  
  for( int i = 0; i < size; i++ ) {
    if( s.at( i ) < t.at( i ) ) {
      large = true;
      break;
    }
    else if( s.at( i ) > t.at( i ) ) {
      large = false;
      break;
    }
    count++;
  }

  if( count == size ) {
    if( s.size() >= t.size() )
      large = false;
    else
      large = true;
  }
    
 
    

  if( large )
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}