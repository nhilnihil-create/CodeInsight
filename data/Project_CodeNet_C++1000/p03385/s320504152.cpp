#include <bits/stdc++.h>
using namespace std;

int main() {
  char s[3];
  for (int i = 0; i < 3; i++)
  cin >> s[i];

  sort(s, s+3);

  if (s[0]=='a' && s[1]=='b' && s[2]=='c')
  cout << "Yes" << endl;
  else
  cout << "No" << endl;
  
}