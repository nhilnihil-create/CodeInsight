#include<bits/stdc++.h>
using namespace std;

int main( void )
{
  int N, A;
  cin >> N >> A;

  while( N >= 500 ) {
    N -= 500;
    //cout << "N:" << N << endl;
  }
  
  if( N <= A )
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

}