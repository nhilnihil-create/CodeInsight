#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAXN 100000

using namespace std;

struct POINT {
  int a,b;
};

POINT A[MAXN];

bool compr ( POINT &x, POINT &y )
{
  return x.b < y.b;
}

int func ( int n, int m )
{
  //cout << "testaaaa\n";
  sort(A,A+m, compr );
  int tmp = -1;
  int sum = 0;
  //cout << " testaa\n";

  /*
  for ( int i = 0; i < m; ++i ) {
    cout << A[i].a << " " << A[i].b << "\n";
  }*/

  for ( int i = 0; i < m; ++i )
  {
    if ( A[i].a <= tmp ) continue;
    tmp = A[i].b-1;
    ++sum;
  }

  return sum;
}

int main()
{
  int n,m;

  cin >> n >> m;

  for ( int i = 0; i < m; ++i )
  {
    int tmpa, tmpb;
    scanf("%d%d", &A[i].a, &A[i].b);
  }

  cout << func(n,m) << endl;
}
