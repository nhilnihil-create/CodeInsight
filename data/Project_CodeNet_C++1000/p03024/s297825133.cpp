#include <iostream>
#include <string>

using namespace std;

int main () {
  string s;
  cin >> s;

  int wins = 0, losses = 0;
  for (char c : s) {
    if (c == 'o') wins++;
    else losses++;
  }

  wins += 15 - (wins + losses);
  if (wins >= 8) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
