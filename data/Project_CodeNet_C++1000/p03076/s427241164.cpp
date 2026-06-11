# include <iostream>
# include <algorithm>
# include <cmath>
using namespace std;

int main() {
  int t_sum = 0;
  int t_diff[5] = {};
  for (int i = 0; i < 5; ++i) {
    int time; cin >> time;
    
    t_diff[i] = ceil(time / 10.0) * 10 - time;
    t_sum += ceil(time / 10.0) * 10;
  }
  
  int max_diff = *max_element(t_diff, t_diff + 5);
  cout << t_sum - max_diff << endl;
  
  return 0;
}