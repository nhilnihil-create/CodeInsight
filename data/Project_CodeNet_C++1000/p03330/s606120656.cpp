#include <iostream>
#include <cstdio>

#define CMAX 30
#define MAXN 500
#define MAX 250000000

using namespace std;

typedef long long ll;

ll A[MAXN+1][MAXN+1];
ll B[CMAX+1][CMAX+1];
ll C[3][CMAX+1];
ll D[3][CMAX+1];
int N, CN;



int main()
{
  ll ans = MAX;

  cin >> N >> CN;
  for ( int i = 1; i <= CN; ++i ) for ( int j = 1; j <= CN; ++j ) scanf("%ld", &B[i][j]);
  for ( int i = 1; i <= N; ++i ) for ( int j = 1; j <= N; ++j ) scanf("%ld", &A[i][j]);
  for ( int i = 1; i <= N; ++i ) {
    for ( int j = 1; j <= N; ++j ) ++C[(i+j)%3][A[i][j]];
  }


  /*
  cout << "cmatrix\n";
  for ( int i = 0; i < 3; ++i ) {
    for ( int j = 1;  j <= CN; ++j ) cout << C[i][j] << " ";
    cout << endl;
  }
  */

  for ( int i = 0; i < 3; ++i ) {
    for ( int j = 1; j <= CN; ++j ) {
      for ( int k = 1; k <= CN; ++k ) D[i][j] += C[i][k]*B[k][j];
    }
  }

  /*
  cout << "dmatrix\n";

  for ( int i = 0; i < 3; ++i ) {
    for ( int j = 1;  j <= CN; ++j ) cout << D[i][j] << " ";
    cout << endl;
  }
  */

  for ( int i = 1; i <= CN; ++i ) {
    for ( int j = 1; j <= CN; ++j ) {
      if ( j == i ) continue;
      for ( int k = 1; k <= CN; ++k ) {
        if ( k == i || k == j ) continue;
        ll tmp = D[0][i]+D[1][j]+D[2][k];
        if ( ans > tmp ) ans = tmp;
      }
    }
  }

  cout << ans << endl;
}
