#include <iostream>
#include <algorithm>

int main()
{
  int N, x;
  std::cin >> N >> x;
  int a[100];
  for (int i=0; i<N; i++) std::cin >> a[i];
  std::sort(a, a+N);
  int cnt = 0;
  for (; cnt < N && x >= a[cnt]; cnt++) x -= a[cnt];
  if (cnt == N && x>0) std::cout << cnt-1 << std::endl;
  else std::cout << cnt << std::endl;
  return 0;
}
