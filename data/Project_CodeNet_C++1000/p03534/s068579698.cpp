#include <algorithm>
#include <iostream>
#include <string>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)

std::string S;
int cnt[3];

int main()
{
  std::cin >> S;

  rep( i, S.size() )
    ++cnt[S[i]-'a'];

  int mi = *std::min_element( cnt, cnt+3 );

  rep( i, 3 )
  {
    if( cnt[i]-mi >= 2 )
    {
      std::cout << "NO" << std::endl;

      return 0;
    }
  }

  std::cout << "YES" << std::endl;

  return 0;
}