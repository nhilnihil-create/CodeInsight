#include <iostream>
#include <vector>
#include <algorithm>

int const nmax = 300;
char v[1 + nmax][1 + nmax];

int main() {
  int n;
  std::cin >> n;
  for(int i = 0; i < n; i++) 
    for(int j = 0; j < n; j++)
      std::cin >> v[i][j];
  int result = 0;
  for(int h = -n + 1; h <= n - 1; h++) {
    int valid = 1;
    for(int i = 0; i < n; i++) 
      for(int j = 0; j < n; j++) 
        valid &= (v[i][(n + j - h) % n] == v[j][(n + i - h) % n]);

    if(valid == 1)
      for(int i = 0; i < n; i++)
        result += (0 <= (i + h) && (i + h) < n);
  }
  std::cout << result;
  return 0;
}
