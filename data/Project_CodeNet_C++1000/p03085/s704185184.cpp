#include <bits/stdc++.h>
using namespace std;
int main()
  {char b; cin >> b;
  string s = "ACGT";
  cout << "TGCA"[find(s.begin(), s.end(), b) - s.begin()] << endl;}