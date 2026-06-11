#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
  string s;
  int k;
  vector<string> V;

  cin >> s;
  cin >> k;

  for ( int a = 1; a <= k; ++a ) {
    for ( int i = 0; i+a <= s.size(); ++i ) {
      string tmp = "";
      for ( int j = i; j < i+a; ++j ) tmp += s[j];
      V.push_back(tmp);
    }
  }

  sort(V.begin(), V.end());
  unique(V.begin(), V.end());

  cout << V[k-1] << endl;

}
