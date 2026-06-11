#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  string sign;
  int takahashi = 0;
  cin >> sign;
  for (int i = 0; i < (int)sign.size(); i++) {
    takahashi += sign[i] == '+' ? 1 : -1;
  }
  cout << takahashi;
}