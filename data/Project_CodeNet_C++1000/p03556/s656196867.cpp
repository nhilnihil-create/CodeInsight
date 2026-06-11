#include <iostream>
using namespace std;
int main()
{
  int N;
  cin >> N;
  int ans = 0;
  for (int i = 0; i <= N; i++) {
    if (i*i <= N) {
      ans = i*i;
    } else {
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
