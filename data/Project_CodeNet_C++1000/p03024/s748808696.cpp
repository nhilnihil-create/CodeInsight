#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

int main() {
  string s;
  cin >> s;
  int count = 0;
  int nokori = 15 - s.size();
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'o') count++;
  }
  cout << (count + nokori >= 8 ? "YES" : "NO") << endl;
  return 0;
}