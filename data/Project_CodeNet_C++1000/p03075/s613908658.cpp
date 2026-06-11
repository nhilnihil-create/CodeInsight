#include <iostream>
#include <vector>


using namespace std;

int main() {
  int x[5];
  int  k;
  cin >> x[0] >> x[1] >> x[2] >> x[3] >> x[4] >> k;
  if (x[4] - x[0] <= k)
    cout << "Yay!" << endl;
  else
    cout << ":(" << endl;
  return 0;
}
