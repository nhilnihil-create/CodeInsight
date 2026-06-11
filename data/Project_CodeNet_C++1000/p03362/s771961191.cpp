#include <iostream>
#include <vector>

#define MAXN 55555

using namespace std;

bool F[MAXN+1];
vector<int> V;

int main()
{
  int n;
  int cnt = 0;

  cin >> n;

  for ( int i= 2; i <= MAXN; ++i ) F[i] = true;
  for ( int i = 2; i <= MAXN; ++i ) {
    if ( F[i] ) {
      for ( int j = i*2; j <= MAXN; j += i ) F[j] = false;
    }
  }

  for ( int i = 2; i <= MAXN; ++i ) {
    if ( cnt == n ) break;
    if ( F[i] && i%5 == 1 ) {
      cout << i << " ";
      ++cnt;
    }
  }

  cout << endl;

}
