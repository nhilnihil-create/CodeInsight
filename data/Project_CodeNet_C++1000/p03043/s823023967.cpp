#include <iomanip>
#include <iostream>
#include <cmath>
#include <vector>

int exp_over_v(int i, int thres)
{
  int ret = 0;
  while(i < thres) {
    i *= 2;
    ret++;
  }
  return ret;
}

int main()
{
  double N, K;
  std::cin >> N >> K;

  double prob = 0.0;
  for(int i=1; i<=N; i++) {
    int e = exp_over_v(i, K);
    prob += std::pow(0.5, e);
  }
  prob /= N;

  std::cout << std::fixed << std::setprecision(15) << prob << std::endl;

  return 0;
}
