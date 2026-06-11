#include <iostream>
#include <vector>

int main()
{
  constexpr int N = 5;
  std::vector<int> times(N);
  int to_be_last = -1;
  int rest = 10;
  for(int i=0; i<N; i++) {
    int t;
    std::cin >> t;
    if(t%10 != 0 && t%10 < rest) {
      to_be_last = i;
      rest = t % 10;
    }
    times[i] = t;
  }

  int m = 0;
  for(int i=0; i<N; i++) {
    if(i == to_be_last) {
      m += times[i];
    } else {
      m += ((times[i] + 9) / 10) * 10;
    }
  }

  std::cout << m << std::endl;
  return 0;
}
