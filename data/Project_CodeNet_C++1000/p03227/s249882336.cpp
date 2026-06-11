#include <algorithm>
#include <iostream>
#include <string>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

std::string S;

int main()
{
  std::cin >> S;

  if( S.size() == 2 )
    std::cout << S << std::endl;
  else
  {
    std::reverse( all(S) );
    std::cout << S << std::endl;
  }

  return 0;
}