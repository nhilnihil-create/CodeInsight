#include<bits/stdc++.h>
using namespace std;

bool check( int A, int B, int i )
{
  int num = 0;
  while( i > 0 ) {
    num += i % 10;
    i /= 10;
  }

  if( A <= num && num <= B )
    return true;
  else
    return false;
}
    
  

int main( void )
{
  int N, A, B;
  cin >> N >> A >> B;
  int sum = 0;
  bool ok = false;
  
  for( int i = 0; i <= N; i++ ) {
    ok = check( A, B, i );
    if( ok )
      sum += i;
  }

  cout << sum << endl;
}