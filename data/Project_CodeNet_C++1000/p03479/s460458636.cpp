#include <iostream>

using namespace std;

typedef long long ll;

#define MAXY 1000000000000000000

int main()
{
  ll X,Y;
  int cnt = 0;

  cin >> X >> Y;

  while ( X <= Y ) {
    ++cnt;
    X *= 2;
  }

  cout << cnt << "\n";
}
