#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
  ll N, a;

  cin >> N;

  for( a = 1; a*a <= N; ++a ) ;
  --a;

  cout << a*a << "\n";
}
