#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S;

  cin >> S;

  int S1 = stoi(S.substr(0, 2));
  int S2 = stoi(S.substr(2, 2));

  if (S1 > 0 && S1 <= 12 && S2 > 0 && S2 <= 12)
  {
    cout << "AMBIGUOUS" << endl;
  }
  else if (S1 > 0 && S1 <= 12)
  {
    cout << "MMYY" << endl;
  }
  else if (S2 > 0 && S2 <= 12)
  {
    cout << "YYMM" << endl;
  }
  else
  {
    cout << "NA" << endl;
  }
}
