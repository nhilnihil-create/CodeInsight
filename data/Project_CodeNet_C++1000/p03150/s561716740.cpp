#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S, K = "keyence";
  cin >> S;
  string revS = S;
  reverse(revS.begin(), revS.end());
  for (int i = 0; i <= S.size(); i++)
  {
    string front = S.substr(0, i);
    for (int j = 0; j <= S.size() - i; j++)
    {
      string back = revS.substr(0, j);
      reverse(back.begin(), back.end());
      if (K == front + back)
      {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
}
