#include <bits/stdc++.h>
using namespace std;
int main() {
  int R; cin >> R; string s = "AGC";
  if(R < 2800) s = "ARC";
  if(R < 1200) s = "ABC";
  cout << s << endl;
}