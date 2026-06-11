#include <iostream>

int main()
{
  int N, M, X;
  std::cin >> N >> M >> X;
  int A[100];
  for (int i=0; i<M; i++) std::cin >> A[i];
  int left = 0;
  int right = 0;
  int i;
  for (i=0; i<M && A[i]<X; i++) left++;
  for (; i<M; i++) right++;
  std::cout << std::min(left, right) << std::endl;
  return 0;
}
