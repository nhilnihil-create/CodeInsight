#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  string n;
  cin >> n;

  if ((n.at(0) == n.at(1) && n.at(1) == n.at(2)) || (n.at(1) == n.at(2) && n.at(2) == n.at(3)))
    cout << "Yes";
  else
  {
    cout << "No";
  }
}
