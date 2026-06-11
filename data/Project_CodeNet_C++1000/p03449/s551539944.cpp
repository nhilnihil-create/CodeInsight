#include<bits/stdc++.h>
using namespace std;

int main( void )
{
  int N;
  cin >> N;
  int A[ 2 ][ N ];
  int sum = 0;
  int count = 0;
  int max = -INT_MAX;

  for( int  i = 0; i < 2; i++ )
    for( int j = 0; j < N; j++ )
      cin >> A[ i ][ j ];

  for( int i = 0; i < N; i++ ) {
    for( int j = 0; j <= N; j++ ) {
      if( count <= i ) {
        //test
        //cout << "+" << A[0][j] << endl;
	sum += A[ 0 ][ j ];
	//test
	//cout << "A[ 0 ][ " << j << " ]" << endl;
      }
	else {
      //cout << "+" << A[1][ j - 1] << endl;
	  sum += A[ 1 ][ j - 1 ];
	  //test
	  //cout << "A[ 1 ][ " << j - 1<< " ]" << endl;
	}
      count++;
    }
    //cout << sum << endl;
      if( max < sum ) {
	max = sum;
      }
    sum = 0;
    count = 0;
  }

    cout << max << endl;
}