#include <iostream>
#include <string>
using namespace std;
int main()
{
  int D;
  cin >> D;
  string ans;
  switch (D) {
    case 25:
      ans = "Christmas";
      break;
    case 24:
      ans = "Christmas Eve";
      break;
    case 23:
      ans = "Christmas Eve Eve";
      break;
    case 22:
      ans = "Christmas Eve Eve Eve";
      break;
  }
  cout << ans << endl;
  return 0;
}
