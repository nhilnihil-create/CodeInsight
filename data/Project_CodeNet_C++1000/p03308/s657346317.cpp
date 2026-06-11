#include <iostream>
using namespace std;
int main()
{
  int N;
  cin >> N;
  int min = 1000000000;
  int max = 1;
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    if (A > max) max = A;
    if (A < min) min = A;
  }
  cout << max-min << endl;
  return 0;
}
