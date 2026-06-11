#include <bits/stdc++.h>
using namespace std;

int main()
{
  string C1, C2;

  cin >> C1 >> C2;

  if ( C1[0] == C2[2]
    && C1[1] == C2[1]
    && C1[2] == C2[0] )
  {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
