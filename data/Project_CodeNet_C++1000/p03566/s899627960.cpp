#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main(){
  int N;
  std::cin >> N;

  std::vector<int> ta(N), va(N);
  for(int i = 0; i < N; i++) std::cin >> ta[i];
  for(int i = 0; i < N; i++) std::cin >> va[i];

  std::vector<int> t_arr(N);
  std::unordered_map<int, int> tv_map, tl_map;
  int t_total = 0;
  tl_map[0] = 0;
  for(int i = 0; i < N; i++){
    int t=ta[i], v=va[i];
    t_arr[i] = t_total;
    tv_map[t_total] = v;
    tl_map[t_total] = std::min(tl_map[t_total], v);
    tl_map[t_total+t] = v;
    t_total += t;
  }
  tl_map[t_total] = 0;

  double prev_v = 0.0;
  double ans = 0;
  for(int i = 0; i <= t_total*2; i++){
    double t = i/2.0;
    double v_max = tv_map[*(std::lower_bound(t_arr.begin(), t_arr.end(), t)-1)];
    for(auto&& it: tl_map){
      v_max = std::min(v_max, std::abs(it.first-t)+it.second);
    }
    ans += 0.5*(prev_v+v_max)*0.5;
    prev_v = v_max;
  }
  std::cout << std::setprecision(9) << ans << std::endl;

  return 0;
}

