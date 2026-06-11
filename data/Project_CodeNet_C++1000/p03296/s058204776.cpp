#include <iostream>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100;
int v[1 + nmax];

int main() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  int result = 0, sum = 0;
  for(int i = 1;i <= n; i++){
    if(v[i] == v[i - 1])
      sum++;
    else {
      result += sum / 2;
      sum = 1;
    }
  }
  result += sum / 2;
  std::cout << result;
}
