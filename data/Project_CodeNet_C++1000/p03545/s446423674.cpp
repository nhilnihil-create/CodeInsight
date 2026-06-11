#include<bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> nums;
  char c;
  for (int i = 0; i < 4; i++) {
    cin >> c;
    nums.push_back(c - '0');
  }
  
  bitset<3> found_bit;
  for (int tmp = 0; tmp < (1 << 3); tmp++) {
    bitset<3> bit(tmp);
    int calc_result = nums.at(0);
    for (int i = 1; i < 4; i++) {
      if (bit.test(i - 1)) {
        calc_result += nums.at(i);
      } else {
        calc_result -= nums.at(i);
      }
    }
    if (calc_result == 7) {
      found_bit = bit;
    }
  }
  
  cout << nums.at(0);
  for (int i = 1; i < 4; i++) {
    if (found_bit.test(i - 1)) {
      cout << "+";
    } else {
      cout << "-";
    }
    cout << nums.at(i);
  }
  cout << "=7" << endl;
}