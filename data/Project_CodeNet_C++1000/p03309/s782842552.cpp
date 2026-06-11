#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

int A[200000];

int main()
{
  int n;
  int b;
  ll sum = 0;
  cin >> n;

  for ( int i = 0; i < n; ++i ) {
    int tmp;
    scanf("%d", &tmp);
    A[i] = tmp-i;
  }

  sort(A,A+n);
  b = ( A[(n-1)/2]);

  for ( int i = 0; i < n; ++i ) {
    sum += abs(A[i]-b);
  }

  cout << sum << endl;
}
