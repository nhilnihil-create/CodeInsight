#include <iostream>

#define MIN ( -1LL << 60 )
#define T 10
#define MAXN 100

typedef long long  ll;

using namespace std;

int A[T];
int N;
int F[MAXN][T];
int P[MAXN][T+1];

ll cal ( int A[] )
{
  ll sum = 0;
  int cnt = 0;

  for ( int i = 0; i < N; ++i ) {
    cnt = 0;
    for ( int j = 0; j < T; ++j ) if ( A[j] == 1 && F[i][j] == 1 ) ++cnt;
    sum += P[i][cnt];
  }

  return sum;
}

ll findmin ( int pos )
{
  if ( pos == T ) {
    for ( int i = 0; i < T; ++i ) if ( A[i] == 1 ) return cal(A);
    return MIN;
  } else {
    ll tmp1, tmp2;
    A[pos] = 0;
    tmp1 = ( findmin(pos+1));
    A[pos] = 1;
    tmp2 = ( findmin(pos+1));

    return max(tmp1,tmp2);
  }
}

int main()
{
  cin >> N;

  for ( int i = 0; i < N; ++i ) for ( int j = 0; j < T; ++j ) scanf("%d", &F[i][j]);
  for ( int i = 0; i < N; ++i ) for ( int j = 0; j <= T; ++j ) scanf("%d", &P[i][j]);

  cout << findmin(0) << "\n";
}
