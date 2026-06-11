#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  vector<string> s(n);
  int c = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> s.at(i);
  }
  for (int i = 0; i < n; i++){
    if (s.at(i) == "Y")
    {
      c = 1;
      break;
    }
  }

  if (c) 
    cout << "Four" << endl;
  else
    cout << "Three" << endl;
  
  return 0;
}