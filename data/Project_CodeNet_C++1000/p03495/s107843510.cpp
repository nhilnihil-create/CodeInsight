#include <iostream>
#include <algorithm>

#define MAXN 200000
typedef long long ll;

using namespace std;

int A[MAXN];

int main()
{
  int N,K;
  ll sum = 0;
  int pos, cnt;
  int kcnt = 0;

  cin >> N >> K;

  for ( int i = 0; i < N; ++i ) {
    int tmp;
    scanf("%d", &tmp);
    --tmp;
    ++A[tmp];
  }

  for ( int i = 0; i < N; ++i ) if ( A[i] > 0 ) ++kcnt;
  sort( A, A+N );

  pos = cnt = 0;
  while ( cnt < kcnt-K ) {
    if ( A[pos] > 0 ) {
      sum += A[pos];
      ++cnt;
    }
    ++pos;
  }

  //for ( int i = 0; i < N; ++i ) cout << A[i] << " ";
  //cout << "\n";
  cout << sum << "\n";
}
