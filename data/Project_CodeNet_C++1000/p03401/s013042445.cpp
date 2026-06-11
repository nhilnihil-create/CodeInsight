#include <iostream>
#include <algorithm>

#define MAXN 100000

using namespace std;

typedef long long ll;

int A[MAXN+1];
int N;

int main ()
{
  ll sum = 0;
  cin >> N;

  for ( int i = 1; i <= N; ++i ) {
    scanf("%d", &A[i]);
    sum += abs(A[i]-A[i-1]);
  }
  sum += abs(A[N]);

  for ( int i = 1; i <= N; ++i ) {
    if ( i != N ) {
      ll tmp = sum;
      tmp += abs(A[i+1]-A[i-1]);
      tmp -= abs(A[i+1]-A[i]);
      tmp -= abs(A[i]-A[i-1]);
      cout << tmp << "\n";
    } else {
      ll tmp = sum;
      tmp -= abs(A[i-1]-A[i]);
      tmp -= abs(A[i]);
      tmp += abs(A[i-1]);
      cout << tmp << "\n";
    }
  }
}
