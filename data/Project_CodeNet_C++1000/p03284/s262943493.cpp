
#include <iostream>
using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  cout << (N + K - 1)/K - N/K;
  return 0;
}
