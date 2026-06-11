#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
  string S;
  cin >> S;
  int a = 0, b = 0, c = 0;
  for (auto& e : S) {
    if (e == 'a') a++;
    if (e == 'b') b++;
    if (e == 'c') c++;
  }
  int mi = min({a, b, c});
  a -= mi;
  b -= mi;
  c -= mi;
  if (a >= 2 || b >= 2 || c >= 2) cout << "NO" << endl;
  else cout << "YES" << endl;

  return 0;
}