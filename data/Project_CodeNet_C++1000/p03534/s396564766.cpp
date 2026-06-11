#include <iostream>
#include <string>

using namespace std;

void failure () {
  cout << "NO" << endl;
  exit(0);
}

int main () {
  string s;
  cin >> s;

  int ac = 0, bc = 0, cc = 0;
  for (char c : s) {
    if (c == 'a') ac++;
    if (c == 'b') bc++;
    if (c == 'c') cc++;
  }

  int n = s.size();
  int ce = (n + 2) / 3;
  int fl = n / 3;

  if (ac != ce && ac != fl) failure();
  if (bc != ce && bc != fl) failure();
  if (cc != ce && cc != fl) failure();
  cout << "YES" << endl;
}
