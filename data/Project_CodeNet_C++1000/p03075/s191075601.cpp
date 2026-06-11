#include <bits/stdc++.h>
using namespace std;

int main() {
  int a[5];
  for (int i = 0; i < 5; i++)
  cin >> a[i];
  int k;
  cin >> k;

  if (a[4]-a[0] <= k)
  cout << "Yay!" << endl;
  else
  cout << ":(" << endl;
}