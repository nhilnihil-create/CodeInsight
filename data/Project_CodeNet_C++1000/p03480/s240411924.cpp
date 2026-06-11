#include <iostream>
#include <algorithm>
#include <string>

#define MAXN 100000

using namespace std;

string s;

int main()
{
  int min = MAXN+1;
  cin >> s;

  for ( int i = 0; i < s.size()-1; ++i ) {
    if ( s[i] != s[i+1] ) {
      int tmp = s.size();
      tmp =  max(i+1, tmp-i-1);
      if ( min > tmp ) min = tmp;
    }
  }

  if ( min == MAXN+1 ) min = s.size();

  cout << min << "\n";
}
