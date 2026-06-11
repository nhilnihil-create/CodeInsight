#include <iostream>
using namespace std;
int main()
{
  int p[5], k;
  cin >> p[0] >> p[1] >> p[2] >> p[3] >> p[4] >> k;
  if ((p[4]-p[0])>k) {
    cout << ":(" << endl;
  } else {
    cout << "Yay!" << endl;
  }
  return 0;
}
