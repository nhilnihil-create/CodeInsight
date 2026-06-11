#include <iostream>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int v[1 + nmax];
int pos[1 + nmax];

int main() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  int smax = 1, sum = 0;
  for(int i = 1;i <= n; i++)
    pos[v[i]] = i;
  for(int i = 1;i <= n; i++) {
    if(pos[i - 1] < pos[i])
      sum++;
    else
      sum = 1;
    smax = std::max(smax, sum);
  }
  std::cout << n - smax;
}
