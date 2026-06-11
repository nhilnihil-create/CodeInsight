#include <iostream>
#include <algorithm>
#include <cmath>

int main()
{
  int n, count;
  bool no_good_result = true;
  int cx, cy, h;
  std::cin >> n;
  int (*coorinates)[3] = new int[n][3];
  for (int i = 0; i < n; i += 1)
    std::cin >> coorinates[i][0] >> coorinates[i][1] >> coorinates[i][2];

  for (cx = 0; cx <= 100 && no_good_result; cx += 1)
    for (cy = 0; cy <= 100 && no_good_result; cy += 1)
    {
      bool all_zero = true, next_coordinate = false;
      for (count = 0; count < n; count += 1)
        if (coorinates[count][2] > 0)
        {
          h = std::abs(cx - coorinates[count][0]) + std::abs(cy - coorinates[count][1]) + coorinates[count][2];
          all_zero = false;
          break;
        }
      if (all_zero)
      {

      }
      for (count = 0; count < n; count += 1)
        if (coorinates[count][2] != std::max(0, h - std::abs(cx - coorinates[count][0]) - std::abs(cy - coorinates[count][1])))
        {
          next_coordinate = true;
          break;
        }
      if (!next_coordinate)
        no_good_result = false;
    }

  std::cout << (cx - 1) << " " << (cy - 1) << " " << h;
  delete[] coorinates;
  return 0;
}