#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  int N, M, X, Y;
  std::cin >> N >> M >> X >> Y;
  std::vector<int> x(N), y(M);
  for (int i = 0; i < N; i++) std::cin >> x.at(i);
  for (int i = 0; i < M; i++) std::cin >> y.at(i);
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  int min_z = x.at(N-1), max_z = y.at(0);
  bool war = true;
  for (int i = Y; i > X; i--)
  {
    if (i <= max_z && i > min_z)
    {
      war = false;
      break;
    }
  }
  if (war) std::cout << "War" << std::endl;
  else std::cout << "No War" << std::endl;
}
