#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

#define MAXN 50

using namespace std;

int A[MAXN];
int N;
vector< pair<int,int> > V;

int func ( void )
{
  int maxpos, minpos;
  int cnt = 0;

  maxpos = minpos = 0;

  for ( int i = 0; i < N; ++i ) {
    if ( A[maxpos] < A[i] ) maxpos = i;
    if ( A[minpos] > A[i] ) minpos = i;
  }

  if ( maxpos == minpos ) return cnt;

  if ( A[minpos] >= 0 ) {
    for ( int i = 1; i < N; ++i ) {
      A[i] += A[maxpos];
      V.push_back({maxpos, i});
      maxpos = i;
      ++cnt;
    }
  } else if ( A[maxpos] <= 0 ) {
    for ( int i = N-1; i >= 0; --i ) {
      A[i] -= A[minpos];
      V.push_back({minpos, i});
      minpos = i;
      ++cnt;
    }
  }

  return cnt;
}

int solve ( void ) {
  int maxpos, minpos;
  int cnt = 0;

  maxpos = minpos = 0;

  for ( int i = 0; i < N; ++i ) {
    if ( A[maxpos] < A[i] ) maxpos = i;
    if ( A[minpos] > A[i] ) minpos = i;
  }

  if ( maxpos == minpos ) return cnt;

  if ( A[maxpos] > 0 && A[minpos] < 0 ) {
    int pos = ( abs(A[maxpos]) > abs(A[minpos]) ) ? maxpos:minpos;
    for ( int i = 0; i < N; ++i ) {
      if ( i != pos ) {
        A[i] += A[pos];
        V.push_back({pos, i});
        ++cnt;
      }
    }
  }

  cnt += func();

  return cnt;
}

int main()
{
  cin >> N;

  for ( int i = 0; i < N; ++i ) scanf("%d", &A[i]);

  cout << solve() << "\n";
  for ( int i = 0; i < V.size(); ++i ) {
    cout << V[i].first+1 << " " <<  V[i].second+1 << endl;
  }

  //for ( int i = 0; i < N; ++i ) cout << A[i] << " "; cout << endl;
}
