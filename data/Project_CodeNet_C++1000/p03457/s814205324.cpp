#include<bits/stdc++.h>
using namespace std;

int main( void )
{
  int N;
  cin >> N;
  int bt = 0, bx = 0, by = 0;
  int at, ax, ay;
  int t, x, y;
  bool can = false;
  
  for( int i = 0; i < N; i++ ) {
    cin >> at >> ax >> ay;
    
    t = at - bt;
    x = abs( ax - bx );
    y = abs( ay - by );

    if( t >= x + y && t % 2 == ( x + y ) % 2 )
      can = true;
    else
      can = false;
    
    bt = at;
    bx = ax;
    by = ay;  
  }

  if( can )
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}