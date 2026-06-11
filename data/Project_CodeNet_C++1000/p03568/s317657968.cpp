#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  int n;
  std::cin >> n;

  vector<int> a(n);
  for(int idx = 0; idx < n; idx++) std::cin >> a[idx];

  int all_combination = pow(3, n);
  int even_num_cnt = 0;
  for(int idx = 0; idx < n; idx++){
    if(a[idx] % 2 == 0){
      even_num_cnt += 1;
    }
  }

  int sub_combination = pow(2, even_num_cnt);

  std::cout << all_combination - sub_combination << '\n';

  return 0;
}
