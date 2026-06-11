
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
  int N[4];
  for (auto & n : N)
    cin >> n;
  sort(N, N + 4);
  if (1 != N[0])
    cout << "NO";
  else if (4 != N[1])
    cout << "NO";
  else if (7 != N[2])
    cout << "NO";
  else if (9 != N[3])
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
