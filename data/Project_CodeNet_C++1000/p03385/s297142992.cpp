#include <iostream>
#include <algorithm>
#include <string>;

using namespace std;

int main()
{
  string s;
  int a,b,c;
  a = b = c = 0;

  cin >> s;

  for ( int i = 0; i < s.size(); ++i ) {
    if ( s[i] == 'a' ) ++a;
    if ( s[i] == 'b' ) ++b;
    if ( s[i] == 'c' ) ++c;
  }

  if ( a == 1 && b == 1 && c == 1 ) cout << "Yes\n";
  else cout << "No\n";
}
