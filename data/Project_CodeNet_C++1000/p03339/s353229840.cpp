#include<bits/stdc++.h>
using namespace std;

int main( void )
{
  int N;
  string S;
  cin >> N >> S;
  int countW = 0, countE = 0;
  int changeW, changeE;
  int minCount = INT_MAX;

  for( int i = 0; i < N; i++ ) {
    if( S.at( i ) == 'W' )
      countW++;
    else
      countE++;
  }

  changeW = 0;
  changeE = countE;
  for( int i = 0; i < N; i++ ) {
    if( S.at( i ) == 'E' )
      changeE--;

    if( changeE + changeW < minCount )
      minCount = changeW + changeE;
    
    if( S.at( i ) == 'W' )
      changeW++;
  }

  cout << minCount << endl;
}