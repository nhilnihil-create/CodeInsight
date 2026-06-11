#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  int blue = 0;
  int red = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'B') {
      blue++;
    }
    if (s[i] == 'R') {
      red++;
    }
  }
  if (red > blue) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
  return 0;
}