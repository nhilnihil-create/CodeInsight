#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  int A, B, C;
  cin >> A >> B >> C;
  int ans = max(max(A*10+B+C, A+B*10+C), A+B+C*10);
  cout << ans << endl;
  return 0;
}
