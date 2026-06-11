#include <iostream>
using namespace std;
int main()
{
  int N;
  cin >> N;
  bool ans = false;
  for (int i = 0; i <= N/4; i++) {
    int n = N - i*4;
    if (n%7==0) ans = true;
  }
  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
