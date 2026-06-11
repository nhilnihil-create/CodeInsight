#include <iostream>
using namespace std;
int main()
{
  int N;
  cin >> N;
  for (int i = N; i <= 999; i++) {
    switch (i) {
      case 111:
      case 222:
      case 333:
      case 444:
      case 555:
      case 666:
      case 777:
      case 888:
      case 999:
        cout << i << endl;
        return 0;
    }
  }
  return 0;
}
