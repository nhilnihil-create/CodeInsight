#include <iostream>

#define MAXN 200001
#define MAXC 30

using namespace std;

int A[MAXC][MAXN];

int main()
{
  int N,C;
  int s,t,c,max;

  cin >> N >> C;
  while ( N-- ) {
    scanf("%d%d%d", &s, &t, &c);
    --c;
    if ( A[c][s*2] < 0 ) ++A[c][s*2];
    else ++A[c][s*2-1];
    if ( A[c][t*2-1] > 0 ) --A[c][t*2-1];
    else --A[c][t*2];
  }

  for ( int i = 0; i < C; ++i ) {
    for ( int j = 1; j < MAXN; ++j ) A[i][j] = A[i][j-1]+A[i][j];
  }
  max = 0;

  for ( int i = 0; i < MAXN; ++i ) {
    int tmp = 0;
    for ( int j = 0; j < C; ++j ) {
      tmp += A[j][i];
    }
    if ( tmp > max  ) max = tmp;
  }

  cout << max << "\n";

  /*
  cout << "\n";
  for ( int i = 0; i < C; ++i ) {
    for ( int j = 0; j < 31; ++j ) cout << A[i][j] << " ";
    cout << "\n";
  }
  */
}
