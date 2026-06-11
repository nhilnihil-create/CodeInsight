#include <iostream>

using ll = long long;
using namespace std;

int main() {
  int bill_num;
  int sum;

  cin >> bill_num >> sum;

  int large_ans, midddle_ans, small_ans;
  large_ans = midddle_ans = small_ans = -1;
  for(int large_num = 0; large_num <= bill_num; large_num++) {
    for(int middle_num = 0; middle_num + large_num <= bill_num; middle_num++) {
      int small_num = bill_num - large_num - middle_num;

      ll candidate_sum = 10000 * large_num + 5000 * middle_num + 1000 * small_num;
      if(candidate_sum == sum) {
        large_ans = large_num;
        midddle_ans = middle_num;
        small_ans = small_num;
      }
    }

  }

  cout << large_ans << ' ' << midddle_ans << ' ' << small_ans << endl;
}