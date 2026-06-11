#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int point_num;
  cin >> point_num;

  int previous_x, previous_y;
  int previous_t;
  previous_x = previous_y = 0;
  previous_t = 0;

  bool can = true;
  for(int i = 0; i < point_num; i++)  {
    int x, y;
    int t;
    cin >> t >> x >> y;

    int diff_x = abs(x - previous_x);
    int diff_y = abs(y - previous_y);
    int diff_t = t - previous_t;

    int left_t = diff_t - (diff_x + diff_y);

    if(left_t < 0 || left_t % 2 != 0) {
      can = false;
      break;
    }

    previous_x = x;
    previous_y = y;
    previous_t = t;
  }

  if(can) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}