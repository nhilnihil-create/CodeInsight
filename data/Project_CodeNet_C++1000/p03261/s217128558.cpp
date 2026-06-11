#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<string> w(n);

  cin >> w[0];

  for (int i = 1; i < n; i++)
  {
    cin >> w[i];
    if (w[i - 1].substr(w[i - 1].length() - 1, 1) != w[i].substr(0, 1))
    {
      cout << "No" << endl;
      return 0;
    }
    for (int j = 0; j < i; j++)
    {
      if (w[i] == w[j])
      {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
}
