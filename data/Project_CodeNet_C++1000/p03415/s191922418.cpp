#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<string> C(3);
  for (int i = 0; i < 3; i++)
    cin >> C.at(i);

  cout << C.at(0).at(0) << C.at(1).at(1) << C.at(2).at(2) << endl;
}
